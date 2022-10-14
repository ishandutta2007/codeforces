#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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
const int maxn = 3e5 + 5;
ll fact[maxn], n, m, ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	fact[0] = 1;
	for(ll i = 1; i < maxn; i++)
		fact[i] = (fact[i-1]*i)%m;
	for(ll l = 1; l <= n; l++) {
		ll t = ((n-l+1)*1ll*fact[n-l+1])%m;
		(t *= fact[l])%=m;
		ans = (ans + t)%m;
	}
	cout << ans;
}