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
const ll mod = (119 * (1 << 23) + 1);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c, hr, hb, wr, wb, ans = 0;
	cin >> c >> hr >> hb >> wr >> wb;
	if(wr*wr>c||wb*wb>c) {
		if(wr < wb) swap(wr, wb), swap(hr, hb);
		for(ll c1 = 0; c1*wr <= c; c1++) {
			ans = max(ans, c1*hr  + hb*((c-c1*wr)/wb));
		}
	} else {
		if(hb*wr < wb*hr) swap(wr, wb), swap(hr, hb);
		set<int> rem;
		for(ll c1 = 0; c1*wr <= c; c1++) {
			if(!rem.insert((c1*wr)%wb).second) break;
			ans = max(ans, c1*hr  + hb*((c-c1*wr)/wb));
		}
	}
	cout << ans;
}