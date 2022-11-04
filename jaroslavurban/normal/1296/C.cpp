#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define inf 10000000


int main(){
	ll t, n;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		cin >> n;
		ll l = -1, r = n;
		map<pair<ll,ll>, ll> pos;
		pair<ll,ll> cur = {0, 0};
		pos[cur] = 0;
		for (ll j = 0; j < n; ++j){
			char c;
			cin >> c;
			if (c == 'L') cur.ff--;
			if (c == 'R') cur.ff++;
			if (c == 'U') cur.ss++;
			if (c == 'D') cur.ss--;
			if (pos.count(cur)){
				if (r - l > j - pos[cur]){
					l = pos[cur];
					r = j;
				}
			}
			pos[cur] = j + 1;
		}
		if (l != -1)
			cout << l + 1 << " " << r + 1 << endl;
		else cout << l << endl;
	}
}