#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 300100;
int n, k, ans[N], ss[N], ssz, sz[N], m, p;
vector <int> v[N];

set<pair<int, int> > s[N];

template<class T>
ostream& operator<<(ostream& out, set<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

int dfs(int node){
	int szmax = 0, ind = -1;
	sz[node]++;
	for(auto i : v[node]) {
		sz[node] += dfs(i);
		if(sz[i] > szmax)
			szmax = sz[i], ind = i;
	}
	if(ind >= 0)
		ss[node] = ss[ind];
	else 
		ss[node] = ssz++;

	for(auto i : v[node])
		if(i != ind)
			for(auto j : s[ss[i]])
				s[ss[node]].insert(j);
	s[ss[node]].insert({sz[node], node});
	// dbg(node);
	// dbg(s[ss[node]]);
	ans[node] = s[ss[node]].lower_bound({sz[node] / 2 + 1, 0})->nd;
	return sz[node];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 2; i <= n; i++) {
		cin >> p;
		v[p].push_back(i);
	}

	dfs(1);

	for(int i = 1; i <= m; i++) {
		cin >> p;
		cout << ans[p] << '\n';
	}

}