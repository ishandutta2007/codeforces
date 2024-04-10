//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef double ld;
typedef pair<ll, ll> pll;

const ll maxn = 22;
const ll maxm = (1 << 20) + 1000;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-7;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, k, m;
ld p[maxn], a[maxm], b[maxm];

int main(){
    fast_io;
    cout << setprecision(10) << fixed;
    
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
    	cin >> p[i];
    	if(p[i] > eps) m++;
	}
	k = min(m, k);
	for(ll i = 0; i < (1 << n); i++){
		ld x = 0;
		ll cc = 0;
		for(ll j = 0; j < n; j++){
			if((i >> j) & 1) x += p[j], cc++;
		}
		if(cc & 1) a[i] = (1.0 / (1 - x));
		else a[i] = -(1.0 / (1 - x));
	}
	for(ll j = 0; j < n; j++){
		for(ll i = 0; i < (1 << n); i++){
			if((i >> j) & 1) a[i] += a[i ^ (1 << j)];
		}
	}
	for(ll i = 0; i < (1 << n); i++){
		ld x = 0;
		for(ll j = 0; j < n; j++){
			if((i >> j) & 1){
				x += p[j] * a[i ^ (1 << j)];
			}
		}
		b[i] = abs(x);
	}
	for(ll j = 0; j < n; j++){
		ld x = 0;
		for(ll i = 0; i < (1 << n); i++){
			if(__builtin_popcount(i) == k && ((i >> j) & 1)){
				x += b[i];
			}
		}
		cout << x << " ";
	}
 
    return 0;
}