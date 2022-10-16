#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 400100;
int n, k, use[N], m, q, x, y;
vector <int> v[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

vector <int> lin[N], col[N];

void dfs(int node) {
	use[node] = 1;
	for(auto i : v[node])
		if(!use[i])
			dfs(i);
} 

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> q;

	for(int i = 1; i <= q; i++) {
		cin >> x >> y;

		v[x].push_back(y + n);
		v[y + n].push_back(x);
	}

	int ans = 0;
	for(int i = 1; i <= n + m; i++)
		if(!use[i])
			dfs(i), ans++;

	cout << ans - 1 << '\n';


}