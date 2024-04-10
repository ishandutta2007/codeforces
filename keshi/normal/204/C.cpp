//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ps[2][26][maxn];

__int128 ans;

string a, b;

int main(){
	fast_io;
	
	cout << setprecision(10) << fixed;
	
	cin >> n >> a >> b;
	
	for(ll i = n; i--;){
		for(ll j = 0; j < 26; j++){
			ps[0][j][i] = ps[0][j][i + 1];
			ps[1][j][i] = ps[1][j][i + 1];
		}
		ps[0][a[i] - 'A'][i] += n - i;
		ps[1][b[i] - 'A'][i] += n - i;
	}
	
	for(ll i = 0; i < n; i++){
		ans += (i + 1) * ps[1][a[i] - 'A'][i];
		ans += (i + 1) * ps[0][b[i] - 'A'][i];
		if(a[i] == b[i]) ans -= (i + 1) * (n - i);
	}
	
	cout << ans * 6.0 / (n * (n + 1) * (2 * n + 1));
	
	return 0;
}