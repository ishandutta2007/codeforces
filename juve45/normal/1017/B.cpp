#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k, f[566], nr00, nr10;
string s, t;

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
	cin >> n;
	cin >> s >> t;

	for(auto i : s)
		f[i - '0']++;

	for(long long i = 0; i < n; i++) {
		if(s[i] == '0' && t[i] == '0')
			nr00++;
		if(s[i] == '1' && t[i] == '0')
			nr10++;
	}

	cout << nr00 * f[1] + nr10 * f[0] - nr00 * nr10 << '\n';
}