#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
long long n, k, p;

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

long long use, init, a[N], b[N];

bool check(long double mid) {
	long double req = 0;
	for(int i = 1; i <= n; i++) {
		long double rest = (long double) b[i] - a[i] * mid;
		if(rest < 0) req -= rest;
	}
	req /= p;
	if(req <= mid)
		 return true;
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(5);
	cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		use += a[i];
	}

	if(p >= use) {
		cout << "-1";
		return 0;
	}
	long double l = 0;
	long double r = 1e15;

	for(int i = 1; i <= 160; i++) {
		long double mid = (l + r) / 2;
		dbg(mid);
		if(check(mid))
			l = mid;
		else 
			r = mid;
	}
	cout << l << '\n';
}