//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1100;
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

ll n, a[maxn], ps[maxn], mn[maxn][maxn], ans;

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(i & 1) ps[i] = ps[i - 1] + a[i];
		else ps[i] = ps[i - 1] - a[i];
	}
	for(ll i = 0; i <= n; i++){
		mn[i][i] = ps[i];
		for(ll j = i + 1; j <= n; j++){
			mn[i][j] = min(mn[i][j - 1], ps[j]);
		}
	}
	for(ll i = 0; i <= n; i += 2){
		for(ll j = i + 2; j <= n; j += 2){
			ans += max(0ll, mn[i + 1][j - 1] - max(ps[i], ps[j]) + 1);
			if(i + 2 == j) ans--;
		}
	}
	cout << ans;
	
	return 0;
}