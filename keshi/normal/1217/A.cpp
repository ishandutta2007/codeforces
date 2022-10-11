#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

long double t, a, b, c, d;
ll ans;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b >> c;
		d = floor((b + c - a) / 2);
		if(d < 0){
			d = -1;
		}
		ans = c - d;
		if(ans < 0){
			ans = 0;
		}
		cout << ans << endl;
	}
	
	return 0;
}