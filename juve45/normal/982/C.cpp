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

int n, k, use[DMAX], w[DMAX], a, b;

vector <int> v[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int dfs(int k) {
	use[k] = 1;
	w[k] = 1;
	for(auto i : v[k])
		if(!use[i])
			w[k] += dfs(i);
	return w[k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	if(n % 2 == 1) {
		cout << "-1\n";
		return 0;
	}

	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(w[i] % 2 == 0) ans++;
	cout << ans - 1<< '\n';

}