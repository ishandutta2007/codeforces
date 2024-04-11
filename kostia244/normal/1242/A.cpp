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
ll n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll ans = -1;
	for(ll d = 2; d*d <= n; d++) {
		if(n%d) continue;
		ans = d;
		break;
	}
	if(ans==-1) return cout << n, 0;
	while(n%ans==0) n/=ans;
	if(n!=1) ans=1;
	cout << ans;
}