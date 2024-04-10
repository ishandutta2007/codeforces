#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	int x, y;
    	cin >> x >> y;
    	vi a(6);
    	for(int i = 0; i < 6; i++) {
    		cin >> a[i];
    	}
    	for(int o = 0; o < 40; o++) {
    		for(int i = 0; i < 6; i++) {
    			a[i] = min(a[i], a[(i + 1) % 6] + a[(i + 5) % 6]);
    		}
    	}
    	ll ans = 0;
    	if(x > 0 && y > 0) {
    		ll dt = min(x, y);
    		ans += dt * a[0];
    		x -= dt;
    		y -= dt;
    	}
    	if(x < 0 && y < 0) {
    		ll dt = -max(x, y);
    		ans += dt * a[3];
    		x += dt;
    		y += dt;
    	}
    	if(x > 0) {
    		ll dt = x;
    		ans += dt * a[5];
    		x -= dt;
    	} else {
    		ll dt = -x;
    		ans += dt * a[2];
    		x += dt;
    	}
    	if(y > 0) {
    		ll dt = y;
    		ans += dt * a[1];
    		y -= dt;
    	} else {
    		ll dt = -y;
    		ans += dt * a[4];
    		y += dt;
    	}
    	cout << ans << '\n';
    }

}