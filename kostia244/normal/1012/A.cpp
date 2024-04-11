#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC comment("/STACK:26666666")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int mod = 1e9 + 7;
int n;
vi a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(2*n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	ll ans1 = (a[n-1]-a[0])*1ll*(a.back()-a[n]);
	ll ans2 = LLONG_MAX;
	for(int i = n; i < 2*n; i++) {
		ans2 = min(ans2, a[i]-a[i-n+1]);
	}
	ans2*=a.back()-a[0];
	cout << min(ans1, ans2) << "\n";
}