#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 200100;
int n, k, m, a, b, use[N];
vector <int> v[N];


template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}
struct asd {
	int a, b, c;
};
vector <asd> ans;
pair<int, int> edge[N];

ostream& operator<<(ostream& out, asd p) {
	return out << p.a << ' ' << p.b << ' ' << p.c;  
}

bool dfs(int k, int t, int d) {
	// dbg(k);
	use[k] = d;
	vector <int> ret;

	for(auto i : v[k])
		if(!use[i]) {
			if(!dfs(i, k, d + 1))
				ret.push_back(i);
		} else if(use[i] > d)
			ret.push_back(i);

	int ok = 0;
	if(ret.size() % 2 == 1 && t != -1)
		ret.push_back(t), ok = 1;

	// dbg(k);
	// dbg(ret);

	for(int i =0; i + 1 < ret.size(); i += 2)
		ans.push_back({ret[i], k, ret[i + 1]});

	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int nrc = 0;
	for(int i = 1; i <= n; i++)
		if(!use[i]) 
			dfs(i, -1, 1);

	cout << ans << '\n';
}