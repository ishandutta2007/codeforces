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

int n, k, m, f[DMAX], a, b, ans, cresc[DMAX], desc[DMAX], h[DMAX], mc[DMAX], md[DMAX];
double l, v1, v2;
string s;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++ ){
		cin >> a >> b;
		f[a]++;
		f[b + 1]--;
	}
	for(int i = 2; i <= m; i++)
		f[i] += f[i - 1];

	int lgmax = 1;
	for(int i = 0; i <= m + 1; ++i) 
		h[i] = 1000000000;

	for(int i = 1; i <= m; i++) {
		int lg = upper_bound(h + 1, h + m + 1, f[i]) - h;
		cresc[i] = lg;
		h[lg] = min(f[i], h[lg]);
	}


	lgmax = 1;
	for(int i = 0; i <= m + 1; ++i) 
		h[i] = 1000000000;
	for(int i = m; i >= 1; i--) {
		int lg = upper_bound(h + 1, h + m + 1, f[i]) - h;
		desc[i] = lg;
		h[lg] = min(f[i], h[lg]);	
	}

	mc[1] = cresc[1];
	for(int i = 2; i <= m; i++)
		mc[i] = max(mc[i - 1], cresc[i]);

	md[m] = desc[m];
	for(int i = m - 1; i >= 1; i--) 
		md[i] = max(md[i + 1], desc[i]);


	for(int i = 0; i <= m; i++) 
		ans = max(mc[i] + md[i + 1], ans);
	cout << ans << '\n';
}