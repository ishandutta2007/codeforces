#include<bits/stdc++.h>
#define all(x) x.end(), x.begin()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
ll n, k;
vi a;

bool canl(int x) {
	ll ans = 0;
	for(auto &i : a) ans += max(0ll, x-i);
	return ans<=k;
}
void apply(ll x) {
	ll ans = k;
	for(auto &i : a) ans -= max(0ll, x-i), i = max(i, x);
	for(auto &i : a)if(ans&&i==x) ans--, i++;
}
void apply2(ll x) {
	ll ans = k;
	for(auto &i : a) ans -= max(0ll, i-x), i = min(i, x);
	for(auto &i : a)if(ans&&i==x) ans--, i--;
}
bool canr(int x) {
	ll ans = 0;
	for(auto &i : a) ans += max(0ll, i-x);
	return ans<=k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	a.resize(n);
	for(auto &i : a) cin >> i;
	int ans = 0;
	for(int i = 1<<29;i;i>>=1)if(canl(ans+i)) ans+=i;
	apply(ans);
	ll l = ans;
	ans = 0;
	for(int i = 1<<29;i;i>>=1)if(!canr(ans+i)) ans+=i;
	ans++;
	apply2(ans);
	for(auto i : a) l=min(l, i);
	cout << ans-l;
}