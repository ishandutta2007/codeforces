#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 300100
#define NMAX 
#define MMAX 

using namespace std;

int n, k;
int pre[DMAX], use[DMAX], ok[DMAX], ok1[DMAX], m, a, b;
vector <int> v[DMAX], ans, c;
int kAns = 1e9, snode = -1, gg = -1;

void dfs(int k) {
	use[k] = 1;
	c.push_back(k);
	for(auto i : v[k])
		if(!use[i])
			dfs(i);
}

bool is_complete() {
	for(auto i : c)
		if(v[i].size() != c.size() - 1)
			return false;
	return true;
}

bool bfs() {
	memset(use, 0, sizeof use);
	queue <int> q; q.push(1); use[1] = 1; pre[1] = -1;
	while(!q.empty()) {
		auto x = q.front(); q.pop();
		for(auto i : v[x]) if(!use[i])
			q.push(i),
			pre[i] = x,
			use[i] = 1;
	}
	if(use[n])
		return true;
	return false; 
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >>a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(auto i : v[1]) ok1[i] = 1;
	dfs(1);

	if(is_complete()) {
		if(use[n] == 1) cout << "1\n1 " << n << "\n";
		else cout << "-1\n";
		return 0;
	} else {
		if(bfs()) {
			int aux = pre[n];
			while(aux != -1) ans.push_back(aux), aux = pre[aux];
			reverse(ans.begin(), ans.end());
			if(ans.size() <= 4) {
				cout << ans << n << '\n';
				return 0;
			}
		}
				
		for(auto i : v[1]) 
			for(auto j : v[i])
				if(!ok1[j] && j != 1) {
					cout << "4\n1 " << i << ' ' << j << " 1 " << n << '\n';
					return 0;
				}

		for(auto i : v[1])
			if(v[i].size() < c.size() - 1) {
				set<int> s;
				for(auto j : v[i]) s.insert(j);
				for(auto j : v[i]) if(j != 1) 
					for(auto k : v[j]) if(k != i && k != 1 && s.count(k) == 0) {
							cout << "5\n1 " << i << ' ' << j << ' ' << k << " " << i << " " << n << '\n';
							return 0;
						}
			}

		cout << "-1\n";
		return 0;
	}
}