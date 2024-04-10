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

ll n, q, gr[maxn][27], a[maxn], f[maxn], prv[maxn][27], nxt[maxn][27], fp[maxn], grp[maxn][27];
vector<ll> vec;
string s;
bool vis[maxn];

int main(){
    fast_io;

	cin >> s;
	n = Sz(s);
	a[0] = a[n + 1] = 26;
	for(ll i = 1; i <= n + 1; i++){
		if(i <= n) a[i] = s[i - 1] - 'a';
		for(ll j = 0; j < 27; j++){
			prv[i][j] = prv[i - 1][j];
		}
		prv[i][a[i]] = i;
	}
	fill(nxt[n + 1], nxt[n + 1] + 27, n + 1);
	for(ll i = n; i >= 0; i--){
		for(ll j = 0; j < 27; j++){
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][a[i]] = i;
	}
	vec.pb(26);
	for(ll i = n; i > 0; i--){
		if(nxt[i + 1][a[i]] != n + 1){
			vec.erase(find(all(vec), a[i]));
		}
		vec.pb(a[i]);
		f[i] = gr[i + 1][a[i]] ^ f[nxt[i + 1][a[i]]];
		for(ll j = Sz(vec) - 1; j >= 0; j--){
			fill(vis, vis + 27, 0);
			for(ll k = Sz(vec) - 1; k > j; k--){
				vis[gr[i][vec[k]]^f[nxt[i][vec[k]]]^f[prv[nxt[i][vec[j]]][vec[k]]] ^ gr[prv[nxt[i][vec[j]]][vec[k]] + 1][vec[j]]] = 1;
			}
			for(ll k = 0; k < 27; k++){
				if(!vis[k]){
					gr[i][vec[j]] = k;
					break;
				}
			}
		}
	}
	vec.clear();
	for(ll i = 1; i <= n; i++){
		if(prv[i - 1][a[i]] != 0){
			vec.erase(find(all(vec), a[i]));
		}
		vec.pb(a[i]);
		fp[i] = gr[i - 1][a[i]] ^ fp[prv[i - 1][a[i]]];
		for(ll j = Sz(vec) - 1; j >= 0; j--){
			fill(vis, vis + 27, 0);
			for(ll k = Sz(vec) - 1; k > j; k--){
				vis[grp[i][vec[k]]^f[prv[i][vec[k]]]^f[nxt[prv[i][vec[j]]][vec[k]]] ^ grp[nxt[prv[i][vec[j]]][vec[k]] - 1][vec[j]]] = 1;
			}
			for(ll k = 0; k < 27; k++){
				if(!vis[k]){
					grp[i][vec[j]] = k;
					break;
				}
			}
		}
	}

	cin >> q;
	for(ll i = 0; i < q; i++){
		ll l, r;
		cin >> l >> r;
		fill(vis, vis + 27, 0);
		for(ll j = 0; j < 26; j++){
			if(nxt[l][j] > r) continue;
			vis[gr[l][j] ^ f[nxt[l][j]] ^ f[prv[r][j]] ^ grp[r][j]] = 1;
		}
		cout << (vis[0] ? "Alice" : "Bob") << '\n';
	}

    return 0;
}