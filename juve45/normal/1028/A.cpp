#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#ifndef LOCAL
#define cerr if(0)cout
#endif

#define st first
#define nd second

using namespace std;

int n, k, m;
string s;
template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n>> m;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		int st = 10000, fi;
		for(int j = 0; j < s.size(); j++)
			if(s[j] == 'B')
				st = min(st, j), fi = j;
		if(st <= m+2) {
			int side = fi - st + 1;
			cout << i + side / 2 << ' ' << 1 + (st + fi)/2 << '\n';

			return 0;
		}
	}
}