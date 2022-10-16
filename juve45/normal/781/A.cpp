#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 200100;
int n, k, a, b, color[N];
vector <int> v[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}


void dfs(int node, int t) {

	int col = 1;
	for(auto i : v[node])	{
		if(i == t) continue;
		while(col == color[t] || col == color[node]) col++;
		color[i] = col++;
	}

	for(auto i : v[node])
		if(i != t)
			dfs(i, node);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int ans = 1;
	for(int i = 1; i <= n; i++)
		ans = max(ans, (int)v[i].size() + 1);
	cout << ans << '\n';

	color[1] = 1;
	dfs(1, -1);
	for(int i = 1; i <= n; i++)
		cout << color[i] << ' ';
}