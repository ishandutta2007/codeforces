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
const ll mod = 1e9+7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, k, __sum = 0;
vi a;

bool can(ll X) {
	if(X == 0)return false;
	vi ev;
	for(auto i : a) {
		ev.pb(i);
		ev.pb(i+1);
		if(i-X+1>=0)
		ev.pb(i-X+1);
		if(i-X>=0)
		ev.pb(i-X);
	}
	sort(all(ev));
	ev.erase(unique(all(ev)), ev.end());
	ll i, j;
	i = j = 0;
	ll smj = __sum;
	ll smi = 0;
	ll ans = LLONG_MAX;
	for(auto L : ev) {
		while(i < a.size() && a[i]<L)
			smi+=a[i++];
		while(j < a.size() && a[j]<=L+X-1)
			smj-=a[j++];
		ans = min(ans, (i*L - smi) + (smj-(n-j)*(L+X-1)));
	}
	return ans<=k;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> k;
	a.resize(n);
	for(auto &i : a) cin >> i, __sum += i;
	sort(all(a));
	ll ans = 0;
	for(int i = 1<<29; i; i>>=1)
		if(!can(ans+i)) ans+=i;
	cout << ans;
}