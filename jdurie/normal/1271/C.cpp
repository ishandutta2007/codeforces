#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, sx, sy, bel = 0, ab = 0, lf = 0, rt = 0;
	cin >> n >> sx >> sy;
	for(ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		if(x < sx) lf++;
		else if(x > sx) rt++;
		if(y < sy) bel++;
		else if(y > sy) ab++;
	}
	ll mx = max(max(ab, bel), max(lf, rt));
	cout << mx << endl;
	if(mx == ab)
		cout << sx << " " << sy + 1 << endl;
	else if(mx == bel)
		cout << sx << " " << sy - 1 << endl;
	else if(mx == lf)
		cout << sx - 1 << " " << sy << endl;
	else
		cout << sx + 1 << " " << sy << endl;
}