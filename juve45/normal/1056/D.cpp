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

const int N = 100100;
int n, k, m, dp[N], a;
vector <int> v[N];

void dfs(int node, int par) {
	if(v[node].size() == 1 && node != 1) {
		dp[node] = 1;
		return;
	}

	for(auto i : v[node])
		if(i != par)
			dfs(i, node);

	for(auto i : v[node])
		if(i != par)
			dp[node] += dp[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	if(n == 1) return cout << "1\n", 0;

	for(int i = 2; i <= n; i++) {
		cin >> a;
		v[a].push_back(i);
		v[i].push_back(a);
	}

	dfs(1, -1);

	sort(dp + 1, dp + n + 1);

	for(int i = 1; i <= n; i++)
		cout << dp[i] << ' ';
}