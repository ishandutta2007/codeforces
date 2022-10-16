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

long long n, k, m, ans;

long long f(long long k) {
	long long ret = n / m;
	if(n % m >= k) ret++;
	if(k == 0) ret--;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(long long i = 0; i < m; i++) 
		for(long long j = 0; j < m; j++) {
			if((i * i + j * j) % m == 0) {
				ans += 1LL * f(i) * f(j);
			}
		}

	cout << ans << '\n';
}