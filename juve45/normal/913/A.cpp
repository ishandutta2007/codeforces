#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, m, x;
string s;

template<class T> ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v)
		out << e << '\n';
	return out;
}

template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> e) {
	out << e.first << ' ' << e.second;
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	if(n >= 30) 
		cout << m << '\n';
	else cout << m % (1 << n) << '\n';

}