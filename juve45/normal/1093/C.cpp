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

const long long N = 200100;
long long n, k, m, a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n / 2; i++) cin >> b[i];

	a[n + 1] = 1e18 + 100;
	for(long long i = 1; i <= n / 2; i++) {
		a[n -  i + 1] = min(a[n - i + 2], b[i] - a[i - 1]);
		a[i] = b[i] - a[n - i + 1];
	}

	for(long long i = 1; i <= n; i++) cout << a[i] << ' ';
}