//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 505, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct prob {
	int e, t;
	bool operator<(const prob& rhs) {
		return t < rhs.t;
	}
};
void solve() {
	vi tmp;
	ll n, t, a, b;
	cin >> n >> t >> a >> b;
	vector<prob> v(n);
	ll ezlft = 0, hlft = 0, mu = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].e;
		if(v[i].e) hlft++;
		else ezlft++;
	}
	for (int i = 0; i < n; i++)
		cin >> v[i].t, tmp.pb(v[i].t - 1), tmp.pb(v[i].t);
	tmp.pb(t);
	tmp.pb(0);
	sort(all(v));
	sort(all(tmp));
	ll ans = 0, j = 0, hv = 0;
	for(auto i : tmp) {
//		cout << i << " ";
		while(j < v.size() && v[j].t <= i) {
			mu++;
			hv+=v[j].e?b:a;
			if(v[j].e) hlft--;
			else ezlft--;
			j++;
		}
		i-=hv;
		if(i<0) continue;
		int qq = min(i/a, ezlft);
		int tt = min((i- qq*a)/b, hlft);
//		cout << mu+qq+tt << "\n";
		ans = max(ans, mu + qq + tt);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}