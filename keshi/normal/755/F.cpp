//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, k, p[maxn], vis[maxn], cnt[maxn];
bitset<maxn> b;

int main(){
    fast_io;
    
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
    	cin >> p[i];
	}
	ll cn = 0;
	for(ll i = 1; i <= n; i++){
		if(vis[i]) continue;
		ll v = i, c = 0;
		do{
			vis[v] = 1;
			v = p[v];
			c++;
		}while(v != i);
		cnt[c]++;
		if(c & 1) cn++;
	}
	b[0] = 1;
	for(ll i = 1; i <= n; i++){
		if(i * 2 < maxn) cnt[i * 2] += (cnt[i] - 1) / 2;
		cnt[i] -= ((cnt[i] - 1) / 2) * 2;
		for(ll j = 0; j < cnt[i]; j++){
			b |= (b << i);
		}
	}
	if(b[k]) cout << k << " ";
	else cout << k + 1 << " ";
	if(n - cn >= 2 * k){
		cout << 2 * k;
	}
	else{
		cout << min(n, k + (n - cn) / 2);
	}
 
    return 0;
}