//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, c1[maxn][maxn], c2[maxn][maxn], d1[maxn][maxn], d2[maxn][maxn];
pll a[maxn][maxn], b[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cin >> a[i][j].F;
			b[j][i].F = a[i][j].F;
			b[j][i].S = i;
			a[i][j].S = j;
		}
		sort(a[i], a[i] + m);
		t = 0;
		for(ll j = m; j--;){
			if(j != m - 1 && a[i][j].F != a[i][j + 1].F) t++;
			c2[i][a[i][j].S] = t;
		}
		t = 0;
		for(ll j = 0; j < m; j++){
			if(j != 0 && a[i][j].F != a[i][j - 1].F) t++;
			c1[i][a[i][j].S] = t;
		}
	}
	for(ll i = 0; i < m; i++){
		sort(b[i], b[i] + n);
		t = 0;
		for(ll j = n; j--;){
			if(j != n - 1 && b[i][j].F != b[i][j + 1].F) t++;
			d2[b[i][j].S][i] = t;
		}
		t = 0;
		for(ll j = 0; j < n; j++){
			if(j != 0 && b[i][j].F != b[i][j - 1].F) t++;
			d1[b[i][j].S][i] = t;
		}
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cout << max(c1[i][j], d1[i][j]) + 1 + max(c2[i][j], d2[i][j]) << " ";
		}
		cout << '\n';
	}
	
	return 0;
}