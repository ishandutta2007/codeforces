#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119*(1<<23) + 1);
void solve() {
	ll n;
	cin >> n;
	vi b3;
	while(n) {
		b3.pb(n%3);
		n/=3;
	}
	b3.pb(0);
	vi bt = b3;
	for(ll i = 0; i+1 < b3.size(); i++) {
		b3[i+1]+=b3[i]/3;
		b3[i]%=3;
		if(b3[i]==2) b3[i]=0, b3[i+1]++;
	}
	reverse(all(b3));
	reverse(all(bt));
	int q = 0;
	for(int i = 0; i < b3.size(); i++) {
		if(!q&&b3[i]>bt[i])q=1;
		else if(q) b3[i]=0;
	}
	ll res = 0;
	for(auto i : b3) res = res*3ll + i;
	cout << res << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}