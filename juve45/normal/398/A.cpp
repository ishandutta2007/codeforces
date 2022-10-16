#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k, a, b;

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


string get_s(long long n) {
	long long pa = a / n;
	long long pb = b/ (n + 1);

	long long na = a % n;
	long long nb = b % (n + 1);

	string ret;
	ret += string(pb, 'x');
	if(nb) ret += 'x', nb--;
	int st = 1;
	for(long long i = 1; i <= n; i++) {
		if(st)
			ret += string(a - n + 1, 'o'), st = 0;
		else
			ret += 'o';

		ret += string(pb, 'x');
		if(nb) ret += 'x', nb--;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> a >> b;

	if(a == 0) {
		cout << -b * b << '\n';
		cout << string(b, 'x');
		return 0;
	}
	long long nrmax = min(a, b + 1);
	long long ans = -1e18;;
	long long ansi = 0;
	for(long long i = 1; i <= nrmax; i++) {
		// dbg(i);
		long long cans = 0;
		long long p = i;
		cans += p - 1 + (a - p + 1) * (a - p + 1);
		dbg(cans);
		p = b / (i + 1);
		dbg(p);
		long long scad = (i + 1 - b % (i + 1)) * (p * p) + (b % (i + 1)) * (p + 1) * (p + 1);
		dbg(scad);
		cans -= scad;

		dbg(cans);
		if(ans < cans)
			ans = cans, ansi = i;
	}
	dbg_ok;
	cout << ans << '\n';
	cout << get_s(ansi);
}