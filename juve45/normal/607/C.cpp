#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;
using ull = unsigned long long;

const int N = 1e6+10;
const ull BASE = 37;
ull n, k, hsh[N];

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


char neg(char c) {
	if(c == 'N') return 'S';
	if(c == 'S') return 'N';
	if(c == 'E') return 'W';
	if(c == 'W') return 'E';
}
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> t;

	ull pb = 1;
	n--;
	for(int lg = 1; lg <= n; lg++) {
		// dbg( pb * (neg(s[n - lg]) - 'A'));
		hsh[lg] = hsh[lg - 1] + pb * (neg(s[n - lg]) - 'A');
		pb *= BASE;
	}

	// dbg_v(hsh, n + 1);

	ull h = 0;
	for(int i = 1; i <= n; i++) {
		h = h * BASE + (t[n - i] - 'A');
		// dbg(h);
		if(hsh[i] == h) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

}