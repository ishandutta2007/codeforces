#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int Q, N, ans;
vector<int> E[303030];

int dfs(int prv, int cur) {
	int M1=0, M2=0, T;
	for (int nxt : E[cur]) {
		if (prv == nxt) continue;
		T = dfs(cur, nxt);

		if (M1<T) { M2=M1; M1=T; }
		else if (M2<T) M2=T;
	}

	ans = max(ans, M1+M2+(int)E[cur].size());
	return M1+E[cur].size()-1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i=1; i<=N; i++) E[i].clear();
		for (int i=1; i<N; i++) {
			int x, y; cin >> x >> y;
			E[x].push_back(y); E[y].push_back(x);
		}

		dfs(0, 1);
		cout << ans+1 << '\n';
		ans = 0;
	}
}