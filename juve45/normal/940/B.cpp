#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, a, b;
long long ans;

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
	cin >> n >> k >> a >> b;
	if(k == 1) {
		cout << 1LL * (n - 1) * a << '\n';
		return 0;
	}

	while(n >= k) {
		if(n % k == 0) {
			long long req = n - (n / k);
			ans += min(req * a, 1LL * b); 
			n = n / k;
		} else {
			ans += 1LL * (n % k) * a;
			n -= (n % k);
		}
	}
	ans += 1LL * (n - 1) * a;
	cout << ans << '\n';
}