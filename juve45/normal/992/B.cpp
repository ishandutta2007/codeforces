#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, l, r, g, llc;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> l >> r >> g >> llc;

	int p = g * llc;

	if(llc % g == 0) {
		int a = llc / g;
		int ans = 0;
		for(int i = 1; i * i <= a; i++) {
			if(a % i == 0) {
				if(__gcd(i, a / i) != 1) continue;
				if(!(l <= g * i && g * i <= r)) continue;
				if(!(l <= g * a/i && g * a/i <= r)) continue;
				if(i * i == a) ans++;
				else ans += 2;
			}
		}
		cout << ans << '\n';
	}
	else return cout << 0 << '\n', 0;
}