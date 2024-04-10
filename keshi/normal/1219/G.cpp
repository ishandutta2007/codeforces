//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, s1_4, s4_1, s1_3, s3_1, s2_2, d1_3, d2_2;

set<pll> Set;

bool f;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	f = 0;
	if(n > m){
		swap(n, m);
		f = 1;
	}
	
	ll a[n + 10][m + 10], b[n + 10], c[m + 10];
	
	fill(b, b + n, 0);
	fill(c, c + m, 0);
	
	if(f){
		for(ll j = 0; j < m; j++){
			for(ll i = 0; i < n; i++){
				cin >> a[i][j];
				b[i] += a[i][j];
				c[j] += a[i][j];
			}
		}
	}
	else{
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				cin >> a[i][j];
				b[i] += a[i][j];
				c[j] += a[i][j];
			}
		}
	}
	
	
	for(ll i = 0; i < n; i++){
		if(m < 3){
			continue;
		}
		Set.clear();
		for(ll j = 0; j < m; j++){
			c[j] -= a[i][j];
			Set.insert({-c[j], j});
		}
		
		d1_3 = b[i];
		ll j1_3 = 0;
		
		for(set<pll>::iterator it = Set.begin(); it != Set.end(); it++){
			if(j1_3 >= 3){
				break;
			}
			d1_3 -= it -> F;
			j1_3++;
		}
		
		s1_3 = max(s1_3, d1_3);
		
		for(ll j = 0; j < m; j++){
			c[j] += a[i][j];
		}
	}
	
	for(ll i = 0; i < m; i++){
		if(n < 3){
			continue;
		}
		Set.clear();
		for(ll j = 0; j < n; j++){
			b[j] -= a[j][i];
			Set.insert({-b[j], j});
		}
		
		d1_3 = c[i];
		ll j1_3 = 0;
		
		for(set<pll>::iterator it = Set.begin(); it != Set.end(); it++){
			if(j1_3 >= 3){
				break;
			}
			d1_3 -= it -> F;
			j1_3++;
		}
		
		s3_1 = max(s3_1, d1_3);
		
		for(ll j = 0; j < n; j++){
			b[j] += a[j][i];
		}
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = i + 1; j < n; j++){
			ll mx1 = 0, mx2 = 0;
			for(ll k = 0; k < m; k++){
				c[k] -= a[i][k] + a[j][k];
				if(c[k] >= mx1){
					mx2 = mx1;
					mx1 = c[k];
				}
				else if(c[k] > mx2){
					mx2 = c[k];
				}
			}
			
			d2_2 = b[i] + b[j] + mx1 + mx2;
			
			s2_2 = max(s2_2, d2_2);
			
			for(ll k = 0; k < m; k++){
				c[k] += a[i][k] + a[j][k];
			}
		}
	}
	
	sort(b, b + n, greater<ll>());
	sort(c, c + m, greater<ll>());
	
	for(ll i = 0; i < min(4ll, n); i++){
		s1_4 += b[i];
	}
	
	for(ll i = 0; i < min(4ll, m); i++){
		s4_1 += c[i];
	}
	
	cout << max(s2_2, max(max(s1_3, s3_1), max(s1_4, s4_1)));
	
	return 0;
}