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

int n, k, x, g, t[DMAX], use[DMAX], a, b, kk;
long long ans = 0;
double l, v1, v2;
vector <int> v[DMAX];
string s;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int dfs(int k) {
	use[k]++;
	int ok = 1, sum = t[k], val;
	for(auto i : v[k]) 
		if(!use[i]){
			val = dfs(i);
			if(val > kk) ok = 0;
			sum += val;
		}
	if(ok && sum >= kk)
		g = k;
	return sum;
}

void dfs(int k, int d) {
	// dbg(k);
	if(t[k]) ans += 1LL * d;
	use[k] = 1;
	for(auto i : v[k])
		if(!use[i])
			dfs(i, d + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> kk;
	for(int i = 1; i <= 2 * kk; i++)
		cin >> x, t[x] = 1;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	// dbg(g);
	memset(use, 0, sizeof use);
	dfs(g, 0);
	cout << ans << '\n';
}