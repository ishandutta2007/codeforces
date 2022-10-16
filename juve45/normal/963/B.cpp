#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 200100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, t[DMAX], g[DMAX], use[DMAX], x, root;

priority_queue <pair<int, int> > p;
vector <int> v[DMAX], ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	// out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}

void dfs(int k, int l) {
	// dbg(k);
	// dbg(g[k]);
	if(g[k] % 2 == 0) 
		p.push({l, k});

	for(auto i : v[k])
		dfs(i, l + 1);
}

void dfs2(int k) {
	ans.push_back(k);
	use[k] = 1;
	for(auto i : v[k])
		if(!use[i])
			dfs2(i);	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x == 0) root = i;
		else {
			v[x].push_back(i);
			t[i] = x;
			g[x]++;
			g[i]++;
		}
	}	

	if(n % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";

	dfs(root, 1);

	while(!p.empty()) {
		auto pp = p.top();
		p.pop();
		// dbg_p(pp);

		if(use[pp.nd] || g[pp.nd] % 2 == 1) continue;

		dfs2(pp.nd);
		
		if(t[pp.nd]) {
			g[t[pp.nd]]--;
			if(g[t[pp.nd]] % 2 == 0) {
				p.push({pp.st - 1, t[pp.nd]});
			}
		}
	}

	cout << ans << '\n';

}