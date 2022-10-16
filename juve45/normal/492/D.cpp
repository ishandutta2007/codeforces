#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

long long n, k, m, x, y, a;

long long cnt(long long val) {
	return val / x + val / y;
}

long long cb(long long k) {
	long long l = 0, r = 1000000000000LL;
	while(l != r) {
		// dbg(l);
		// dbg(r);
		long long mid = (l + r) / 2;
		if(cnt(mid) >= k) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y;

	for(long long i = 1; i <= n; ++i) {
		cin >> a;
		a %= (x + y);
		long long r = cb(a);
		if(r % x == 0 && r % y == 0)
			cout << "Both\n";
		else if(r % x == 0)
			cout << "Vova\n";
		else 
			cout << "Vanya\n";
	}
}