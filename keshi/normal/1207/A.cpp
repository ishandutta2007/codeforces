// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll t, b, p, f, h, c, m, ans;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> b >> p >> f >> h >> c;
		ans = 0;
		if(h >= c){
			m = min(b / 2, p);
			b -= m * 2;
			p -= m;
			ans += m * h;
			m = min(b / 2, f);
			ans += m * c;
		}
		else{
			m = min(b / 2, f);
			b -= m * 2;
			f -= m;
			ans += m * c;
			m = min(b / 2, p);
			ans += m * h;
		}
		cout << ans << endl;
	}
	
	return 0;
}