#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, ans, m, use[N], b, c;
vector <int> v[N], a[3];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


void dfs(int node, int col) {
	use[node] = col;
	a[col].push_back(node);

	for(auto i : v[node]) {
		if(!use[i])
			dfs(i, 3 - col);
		else if(use[i] == col)
			ans = -1;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= m; i++) {
		cin >> c >> b;
		v[c].push_back(b);
		v[b].push_back(c);
	}

	for(int i = 1; i <= n; i++) 
		if(!use[i])
			dfs(i, 1);

	if(ans == -1) 
		return cout << ans, 0;

	cout << a[1] << '\n' << a[2] << '\n';

}