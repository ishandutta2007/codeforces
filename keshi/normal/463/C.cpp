//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2100;
const ll maxm = 4100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn][maxn], r[maxm], c[maxm], w[2];

pll p[2];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			cin >> a[i][j];
			r[i - j + n] += a[i][j];
			c[i + j] += a[i][j];
		}
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(w[(i + j) % 2] <= r[i - j + n] + c[i + j] - a[i][j]){
				w[(i + j) % 2] = r[i - j + n] + c[i + j] - a[i][j];
				p[(i + j) % 2] = {i + 1, j + 1};
			}
		}
	}
	
	cout << w[0] + w[1] << endl;
	
	cout << p[0].F << " " << p[0].S << " " << p[1].F << " " << p[1].S;
	
	return 0;
}