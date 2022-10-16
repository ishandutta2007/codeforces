#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, f[244], ok[244];
string s[DMAX], op[DMAX];


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
	int total_shock = 0;
	for(int i = 1; i <= n; i++) 
		cin >> op[i] >> s[i], total_shock += (op[i][0] != '.');
	
	total_shock--;
	char good = s[n][0];
	int shock = 0;

	for(int i = 1; i < n; i++) {
		// dbg(i);
		if(op[i][0] == '!') {
			for(int j = 0; j < s[i].size(); j++) 
				f[s[i][j] - 'a']+= (ok[s[i][j] - 'a'] != i), ok[s[i][j] - 'a'] = i; 
			shock++;
		}
		if(op[i][0] == '.') for(int j = 0; j < s[i].size(); j++) f[s[i][j] - 'a'] = -1000000;
		if(op[i][0] == '?') {
			// if(f[s[i][0] - 'a'] == f[good - 'a'])
			shock++;
			f[s[i][0] - 'a'] = -1000000; 
		}
		// dbg(shock);
		// dbg_v(f, 27);
		int nr = 0;
		// dbg(good - 'a');
		for(int j = 0; j < 26; j++) {
			if(f[j] == f[good - 'a']) nr++;
		}
		// dbg_ok;
		if(nr == 1) {
			cout << total_shock - shock << '\n';
			return 0;
		}
	}
	cout << 0;
	return 0;
}