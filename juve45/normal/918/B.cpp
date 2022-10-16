#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, m1;
string s, t;
map<string, string> m;


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
	cin >> n >> m1;
	for(int i = 1; i <= n; i++) {
		cin >> s >> t;
		m[t] = s;
	}
	for(int i = 1; i <= m1; i++) {
		cin >> s >> t;
		cout << s << ' ' << t << " #" << m[t.substr(0, t.size() - 1)] << '\n'; 
	}
}