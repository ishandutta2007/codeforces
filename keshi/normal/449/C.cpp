//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, p[maxn], f[maxn], cnt, a[maxn], cc;

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 2; i <= n; i++){
    	if(p[i]) continue;
    	p[i] = i;
    	for(ll j = i * i; j <= n; j += i){
    		if(p[j] == 0) p[j] = i;
		}
	}
	for(ll i = 2; i <= n; i++){
		if(p[i] == i && i * i > n){
			if(i * 2 > n) f[i] = -1;
			else{
				f[i] = i * 2;
				f[i * 2] = i;
				cnt++;
			}
		}
		if(!f[i]) a[m++] = i;
	}
	for(ll i = 0; i + 1 < m; i += 2){
		if(f[a[i + 1]]){
			swap(a[i], a[i + 1]);
			i--;
			continue;
		}
		if(f[a[i]]){
			i--;
			continue;
		}
		ll x = p[a[i]] * p[a[i + 1]];
		if(f[x]){
			if(__gcd(f[x], a[i]) != 1){
				f[f[x]] = a[i];
				f[a[i]] = f[x];
				f[x] = a[i + 1];
				f[a[i + 1]] = x;
			}
			else{
				f[f[x]] = a[i + 1];
				f[a[i + 1]] = f[x];
				f[x] = a[i];
				f[a[i]] = x;
			}
		}
		else{
			f[x] = a[i];
			f[a[i]] = x;
			i--;
		}
		cnt++;
	}
	cout << cnt << "\n";
	for(ll i = 2; i <= n; i++){
		if(f[i] > i){
			cout << i << " " << f[i] << "\n";
		}
	}
	
	
    return 0;
}