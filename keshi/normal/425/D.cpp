//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll sq = 120;
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

ll n, ans;
pll p[maxn];
vector<ll> a[maxn], b[maxn];
ll vis[2][maxn];

int main(){
    fast_io;

	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> p[i].F >> p[i].S;
		a[p[i].F].pb(p[i].S);
	}
	for(ll i = 0; i < maxn; i++){
		if(a[i].empty()) continue;
		sort(all(a[i]));
		if(Sz(a[i]) > sq){
			for(ll j : a[i]){
				vis[0][j] = 1;
			}
			for(ll k = 0; k < i; k++){
				for(ll x : a[k]){
					vis[1][x] = 1;
					if(x - i + k >= 0 && vis[0][x] && vis[0][x - i + k] && vis[1][x - i + k]) ans++;
				}
				for(ll x : a[k]){
					vis[1][x] = 0;
				}
			}
			for(ll j : a[i]){
				vis[0][j] = 0;
			}
		}
		else{
			for(ll j : a[i]){
				for(ll k : a[i]){
					if(k <= j || i - k + j < 0) continue;
					if(binary_search(all(a[i - k + j]), j) && binary_search(all(a[i - k + j]), k)) ans++;
				}
			}
		}
	}
	cout << ans;


    return 0;
}