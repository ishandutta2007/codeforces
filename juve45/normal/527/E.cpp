#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, m, a, b, use[DMAX], last;
vector <int> v[DMAX], ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	// out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void dfs(int k) {
	while(v[k].size()) {
		int to = v[k].back();
		v[k].pop_back();
		v[to].erase(find(v[to].begin(), v[to].end(), k));
		dfs(to);
	}
	ans.push_back(k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i = 1; i <= n; i++) {
		if(v[i].size() % 2 == 1) {
			if(!last)
				last = i;
			else {
				v[i].push_back(last);
				v[last].push_back(i);
				last = 0;
			}
		}
	}
	dfs(1);

	if(ans.size() % 2 == 0)
		ans.push_back(ans.back());

	cout << ans.size() - 1 << '\n';
	for(int i = 1; i < ans.size(); i+= 2) {
		cout << ans[i] << ' ' << ans[i + 1] << '\n';
		cout << ans[i] << ' ' << ans[i - 1] << '\n'; 
	}
}