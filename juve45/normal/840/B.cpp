#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

const int N = 300100;
int n, k, m, use[N], bad[N], d[N], dp[N], ans[N], mm, a, b, rad = 1;
vector <pair<int, int> > v[N];

void dfs(int node) {

	use[node] = 1;
	dp[node] = bad[node];

	for(auto i : v[node])
		if(!use[i.st]) {
			dfs(i.st);
			if(dp[i.st] % 2 == 1) {
				mm--;
				ans[i.nd] = 0;
				dp[node]++;
			}
		}
	if(d[node] == -1)
		dp[node] = 0;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	mm = m;

	for(int i = 1; i <= n; i++)
		cin >> d[i];

	for(int i = 1; i <= m; i++) {
		ans[i] = 1;
		cin >> a >> b;
		v[a].push_back({b, i});
		v[b].push_back({a, i});
	}

	for(int i = 1; i <= n; i++) {
		if(d[i] != -1 && v[i].size() % 2 != d[i])
			bad[i] = 1;
		if(d[i] == -1) rad = i;
	}


	dfs(rad);
	if(dp[rad] == 1) 
		return cout << "-1\n", 0;

	cout << mm << '\n';
	for(int i = 1; i <= m; i++)
		if(ans[i])
			cout << i << ' ';
	// dbg(dp[rad]);
}