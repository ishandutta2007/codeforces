//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 4e5 + 100;
const ll level = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, l, par1[maxn][level], par2[maxn][level], mx[maxn][level], sm[maxn][level], a[maxn], d1[maxn], d2[maxn];

int main(){
	ll v, u, x, c;
	fast_io;
	
	a[0] = inf;
	sm[0][0] = a[0];
	
	d2[1] = 1;
	
	cin >> q;
	
	n = 1;
	
	while(q--){
		cin >> c >> v >> x;
		v ^= l;
		x ^= l;
		if(c == 1){
			n++;
			d1[n] = d1[v] + 1;
			par1[n][0] = v;
			a[n] = x;
			mx[n][0] = a[n];
			for(ll i = 1; i < level; i++){
				if(d1[n] >= (1 << i)){
					par1[n][i] = par1[par1[n][i - 1]][i - 1];
					mx[n][i] = max(mx[n][i - 1], mx[par1[n][i - 1]][i - 1]);
				}
			}
			u = par1[n][0];
			for(ll i = level - 1; i--;){
				if(d1[u] < (1 << i)) continue;
				if(mx[u][i] < a[n]) u = par1[u][i];
			}
			if(a[u] < a[n]) u = 0;
			d2[n] = d2[u] + 1;
			par2[n][0] = u;
			sm[n][0] = a[n];
			for(ll i = 1; i < level; i++){
				if(d2[n] < (1 << i)) continue;
				par2[n][i] = par2[par2[n][i - 1]][i - 1];
				sm[n][i] = sm[n][i - 1] + sm[par2[n][i - 1]][i - 1];
			}
		}
		else{
			u = v;
			for(ll i = level - 1; i--;){
				if(d2[u] < (1 << i)) continue;
				if(sm[u][i] <= x){
					x -= sm[u][i];
					u = par2[u][i];
				}
			}
			l = d2[v] - d2[u];
			cout << l << '\n';
		}
	}
	
	return 0;
}