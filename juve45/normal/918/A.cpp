#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, m[100000], f[100];
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
	f[1] = 0;
	f[2] = 1;
	m[0] = 1;
	for(int i = 3; i <= 18; i++) {
		f[i] = f[i - 1] + f[i - 2];
		// dbg(f[i]);
		m[f[i]] = 1;
	}
	cin >> n;
	for(int i = 1; i <= n; i++) {
		if(m[i]) cout << 'O';
		else cout << 'o';
	}
}