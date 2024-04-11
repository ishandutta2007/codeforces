//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 2e5+3;
ll n, m, k, a[maxn], running[maxn];
bool can(ll x) {
	memset(running, 0, sizeof running);
	ll run = 0, done = 0;
	for(int i = 0; done <= m && i < n; i++) {
		run += running[i];
		ll t = max(0ll, x-(a[i]+run));
		done += t;
		run += t;
		running[i+k]-=t;
	}
	return done <= m;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1<<30; i>>=1;)
		if(can(ans+i)) ans+=i;
	cout << ans;
}