#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 505;
const int MOD = 998244353;
using ll = long long;
ll n, k, a[N], nxt[N * N];

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

ll cb2(ll nr) {
	ll l = 1;
	ll r = 1500000000;
	while(l != r) {
		ll mid = l + (r - l) / 2;
		if(mid * mid < nr) l = mid + 1;
		else r = mid;
	}
	return l;
}


ll cb3(ll nr) {
	ll l = 1;
	ll r = 1357209;
	while(l != r) {
		ll mid = l + (r - l) / 2;
		if(mid * mid * mid < nr) l = mid + 1;
		else r = mid;
	}
	return l;
}


ll cb4(ll nr) {
	ll l = 1;
	ll r = 38729;
	while(l != r) {
		ll mid = l + (r - l) / 2;
		if(mid * mid * mid * mid < nr) l = mid + 1;
		else r = mid;
	}
	return l;
}

map<long long, long long> m;
vector <int> f;
int main() {
	ios_base::sync_with_stdio(false);



	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		nxt[i * i - 1] = (i + 1) * (i + 1) - 1;
		
		ll mid;
		mid = cb4(a[i]);
		if(mid * mid * mid * mid == a[i]) {
			m[mid] += 4;
			a[i] = 0;
			f.push_back(mid);
			continue;
		}
		
		mid = cb2(a[i]);
		if(mid * mid == a[i]) {
			m[mid] += 2;
			a[i] = 0;
			f.push_back(mid);
			continue;
		}

		mid = cb3(a[i]);
		if(mid * mid * mid == a[i]) {
			m[mid] += 3;
			a[i] = 0;
			f.push_back(mid);
			continue;
		}

	}

	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) continue;
		int cnt = 0, ok = 0;

		for(auto j : f) {
			if(a[i] % j == 0) {
				ll g = a[i] / j;
				ok = 1;
				m[j]++;
				m[g]++;
				break;
			}
		}

		for(int j = 1; j <= n && !ok; j++) {
			if(i == j || a[j] == 0) continue;

			ll g = __gcd(a[i], a[j]);

			if(g != a[i] && g != 1) {
				ll g2 = a[i] / g;
				m[g]++;
				m[g2]++;
				ok = 1;
				break;
			}
		}
		if(!ok)
			m[a[i]] = nxt[m[a[i]]];
	}
	ll ans = 1;
	for(auto i : m) {
		ans = (ans * (i.nd + 1)) % MOD;
		// dbg(i);
	}
	cout << ans << '\n';


}