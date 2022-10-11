//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, fen[maxn];

void upd(ll x, ll y){
    for(; x < maxn; x += x & -x){
        fen[x] += y;
    }
    return;
}

ll get(ll x){
    ll y = 0;
    for(; x > 0; x -= x & -x){
        y += fen[x];
    }
    return y;
}

int main(){
    ll x, l, r, mid;
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> x;
		upd(x, 1);
	}
	for(ll i = 0; i < m; i++){
		cin >> x;
		if(x < 0){
		    x = -x;
		    l = 0, r = maxn - 1;
		    while(r - l > 1){
		        mid = (l + r) / 2;
		        if(get(mid) >= x) r = mid;
		        else l = mid;
		    }
		    upd(r, -1);
		}
		else{
		    upd(x, 1);
		}
	}
    for(ll i = 1; i < maxn; i++){
        if(fen[i]){
            cout << i;
            return 0;
        }
    }
    cout << 0;
	
	return 0;
}