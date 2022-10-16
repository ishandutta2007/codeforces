#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, p, a[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long s, lhs, rhs, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s += 1LL * a[i];
	}	

	rhs = s;
	for(int i = 1; i < n; i++) {
		lhs += 1LL * a[i];
		rhs -= 1LL * a[i];
		ans = max(ans, lhs % p + rhs % p);
	}
	cout << ans << '\n';
}