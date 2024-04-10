#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
int par[100010], par2[100010];
int A[100010], B[100010];
vector<pii> S;

int Find(int a) {
	if (par[a] == a) return a;
	return par[a] = Find(par[a]);
}
void Union(int a, int b) {
	if (Find(a) == Find(b)) return;
	par[Find(b)] = Find(a);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> M >> N;
	for (int i=0; i<M; i++) cin >> A[i];
	for (int i=1; i<=N; i++) cin >> B[i];
	for (int i=0; i<M; i++) par[i] = i;

	ll ans = 0;
	for (int i=0; i<M; i++) {
		int x; cin >> x;
		while (x--) {
			int y; cin >> y;
			S.emplace_back(i, y);
			ans += A[i] + B[y];
		}
	}
	sort(S.begin(), S.end(), [&](pii a, pii b) {
		return A[a.va] + B[a.vb] > A[b.va] + B[b.vb];
	});

	for (int i=1; i<=N; i++) par2[i] = -1;
	for (pii pt : S) {
		if (par2[pt.vb] == -1) {
			par2[pt.vb] = pt.va;
			ans -= A[pt.va] + B[pt.vb];
			continue;
		}
		if (Find(pt.va) == Find(par2[pt.vb])) continue;
		Union(pt.va, par2[pt.vb]);
		ans -= A[pt.va] + B[pt.vb];
	}

	cout << ans;
}