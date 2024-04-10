#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAX = 1000010;

int N, M;
int X[2020], Y[2020], ans[MAX+10];
vector<pii> S, T;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) cin >> X[i] >> Y[i];

	int x = *min_element(X, X+N);
	int y = *min_element(Y, Y+N);
	for (int i=0; i<N; i++) {
		X[i] -= x; Y[i] -= y;
	}

	for (int i=0; i<M; i++) {
		int a, b; cin >> a >> b;
		a -= x; b -= y;
		if (a < 0 || b < 0) continue;
		S.emplace_back(a, b);
	}
	sort(S.begin(), S.end());
	for (pii x : S) {
		while (!T.empty() && T.back().vb <= x.vb) T.pop_back();
		T.push_back(x);
	}
	T.emplace_back(MAX+1, -1);

	for (int i=0; i<N; i++) {
		for (int j=0; j<T.size(); j++) {
			if (T[j].va < X[i]) continue;
			ans[T[j].va - X[i]] = max(ans[T[j].va - X[i]], T[j].vb - Y[i] + 1);
		}
	}

	int mn = 2e9;
	for (int i=MAX-2; i>=0; i--) {
		ans[i] = max(ans[i], ans[i+1]);
		mn = min(mn, ans[i] + i);
	}
	cout << mn << '\n';
}