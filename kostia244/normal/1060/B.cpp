#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119*(1<<23) + 1);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll ans = 9, n;
	cin >> n;
	if(n < 10) {
		cout << n;
		return 0;
	}
	ll c = 9;
	while(10*c+9 < n) c = 10*c+9, ans+=9;
	n-=c;
	string t = to_string(n);
	for(auto i : t) ans += i-'0';
	cout << ans;
}