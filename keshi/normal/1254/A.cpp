//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, m, d, k, c, r, v[maxn], f[maxn][maxn];

pll p[4];

string s[maxn];

char g[maxn];

bool val(ll x, ll y){
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	return (f[x][y] == -1);
}

int main(){
	ll x, y;
	p[0] = {0, 1};
	p[1] = {1, 0};
	p[2] = {0, -1};
	p[3] = {-1, 0};
	fast_io;
	
	for(ll i = 0; i < 10; i++){
		g[i] = char('0' + i);
	}
	
	for(ll i = 0; i < 26; i++){
		g[i + 10] = char('a' + i);
	}
	
	for(ll i = 0; i < 26; i++){
		g[i + 36] = char('A' + i);
	}
	
	cin >> t;
	
	while(t--){
		x = 0;
		y = 0;
		d = 0;
		cin >> n >> m >> k;
		c = 0;
		for(ll i = 0; i < n; i++){
			cin >> s[i];
			for(ll j = 0; j < m; j++){
				f[i][j] = -1;
				if(s[i][j] == 'R') c++;
			}
		}
		for(ll i = 0; i < k; i++){
			v[i] = c / k;
		}
		for(ll i = 0; i < c % k; i++){
			v[i]++;
		}
		r = n * m;
		for(ll i = 0; i < k; i++){
			while(v[i]){
				//cout << "# " << i << ", " << v[i] << " => " << x << " " << y << endl;
				f[x][y] = i;
				r--;
				if(s[x][y] == 'R'){
					v[i]--;
				}
				while(r && !val(x + p[d].F, y + p[d].S)){
					d = (d + 1) % 4;
				}
				x += p[d].F;
				y += p[d].S;
			}
		}
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				if(f[i][j] == -1) f[i][j] = k - 1;
				cout << g[f[i][j]];
			}
			cout << '\n';
		}
	}
	
	return 0;
}