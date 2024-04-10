#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 10010
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, c[DMAX], t[DMAX];
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
	cin >> n;
	for(int i = 2; i <= n; i++) {
		cin >> t[i];
	}

	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		if(c[i] != c[t[i]]) 
			ans++;
	}
	cout << ans << '\n';
}