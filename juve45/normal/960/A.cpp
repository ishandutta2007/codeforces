#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, f[255];
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(auto i : s) f[i]++;
	string s2 = "";
	for(int i = 0; i < f['a']; i++) s2 += 'a';
	for(int i = 0; i < f['b']; i++) s2 += 'b';
	for(int i = 0; i < f['c']; i++) s2 += 'c';
	if((f['c'] == f['a'] || f['c'] == f['b']) && s2 == s && f['a'] > 0 && f['b'] > 0)	
		cout << "YES\n";
	else cout << "NO\n";
}