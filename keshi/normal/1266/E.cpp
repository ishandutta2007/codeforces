//In the name of GOD
//Global Round just dont make me blue :)
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

ll n, q, a[maxn], ans, cnt[maxn];

map<ll, ll> gift[maxn];

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ans += a[i];
	}
	
	cin >> q;
	
	for(ll i = 0; i < q; i++){
		cin >> v >> u >> c;
		if(gift[v][u]){
			cnt[gift[v][u]]--;
			if(cnt[gift[v][u]] < a[gift[v][u]]){
				ans++;
			}
			gift[v][u] = 0;
		}
		gift[v][u] = c;
		if(c){
			cnt[c]++;
			if(cnt[c] <= a[c]){
				ans--;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}