#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll a[maxn], b[maxn], n, k;
inline ll eval(ll a, ll b) {
	return 1 + (a/b);
}
inline bool cmp (pair<pair<ll, ll>, pair<ll, ll>> &a, pair<pair<ll, ll>, pair<ll, ll>> &b) {
	return a.second > b.second;
}
pair<pair<ll, ll>, pair<ll, ll>> st[maxn];
inline bool can(ll x) {
	for(int i = 0; i < n; i++)
		st[i].first = {a[i], b[i]},
		st[i].second.first = eval(st[i].first.first, st[i].first.second);
	make_heap(st, st+n, cmp);
	for(int cur = 0; cur < k; cur++) {
		if(st[0].second.first <= cur) {
			return false;
		}
		pop_heap(st, st+n, cmp);
		st[n-1].first.first += x;
		st[n-1].second.first = eval(st[n-1].first.first, st[n-1].first.second);
		push_heap(st, st+n, cmp);
	}
	return true;
}
int main() {
    srand(time(NULL));
	for(int i = 0; i < n; i++)
		st[i] = {{a[i], b[i]}, {-1, rand()}};
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> k;
	ll ans = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	if(can(0)) {
		cout << 0;
		return 0;
	}
	if(!can(1ll<<42)) {
		cout << -1;
		return 0;
	}
	for(ll i = 1ll<<41; i; i>>=1) {
		if(!can(ans+i))
			ans+=i;
	}
	ans++;
	cout << ans;
}