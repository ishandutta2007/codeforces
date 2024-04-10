#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Tup {int x, y, c;};

const int MAX = 2e5;
int N, K;
Tup A[MAX];
vector<int> ans;
set<pii> st;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> K;
	for (int i=0; i<N; i++) {
		cin >> A[i].x >> A[i].y; A[i].c = i+1;
	}
	sort(A, A+N, [&](Tup a, Tup b) { return a.x < b.x; });

	int p=0;
	for (int i=1; i<=MAX; i++) {
		while (!st.empty() && (st.begin()->va)<i) st.erase(st.begin());
		while (p<N && A[p].x == i) {
			st.insert(pii(A[p].y, A[p].c));
			if (st.size()>K) {
				ans.push_back(prev(st.end())->vb);
				st.erase(prev(st.end()));
			}
			++p;
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int x : ans) cout << x << ' ';
}