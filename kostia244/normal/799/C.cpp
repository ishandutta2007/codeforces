#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll go(vector<pair<ll, ll>>& a, int c) {
	multiset<ll, greater<ll>> pr;
	int i, j;
	j=0;
	i=(int)a.size()-1;
	ll ans = 0;
	while(i < a.size()) {
		while(j < i && a[j].first+a[i].first <= c)
			pr.insert(a[j++].second);
		while(j > i)
			pr.erase(pr.find(a[--j].second));
		if(!pr.empty())
		ans = max(ans, a[i].second + *pr.begin());
		i--;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n, c, d;
	cin >> n >> c >> d;
	vector<pair<ll, ll>> f[2];
	char t;
	for(int b, p, i = 0; i < n; i++) {
		cin >> b >> p >> t;
		if(t=='C'&&p<=c)
			f[0].pb({p, b});
		if(t=='D'&&p<=d)
			f[1].pb({p, b});
	}
	sort(all(f[0]));
	sort(all(f[1]));
	ll x, y;
	x = y = 0;
	for(auto i : f[0])
		x = max(x, i.second);
	for(auto i : f[1])
		y = max(y, i.second);
	ll ans =f[0].size()&&f[1].size()? x+y:0;
	ans = max({ans, go(f[0], c), go(f[1], d)});
	cout << ans;
}