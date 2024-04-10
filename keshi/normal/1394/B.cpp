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

ll n, m, k, ans, d[maxn];
vector<pll> g[maxn];
bitset<maxn> b[10][10];
bool ok[10][10][10][10], oo[10][10];

int main(){
    fast_io;

    cin >> n >> m >> k;
    for(ll i = 0; i < m; i++){
        ll v, u, c;
        cin >> v >> u >> c;
        g[v].pb(Mp(c, u));
    }
    for(ll i = 1; i <= n; i++){
        sort(g[i].begin(), g[i].end());
        for(ll j = 0; j < (ll)g[i].size(); j++){
            if(b[g[i].size()][j + 1][g[i][j].S]) oo[g[i].size()][j + 1] = 1;
            b[g[i].size()][j + 1][g[i][j].S] = 1;
        }
    }
    for(ll i = 1; i <= k; i++){
        for(ll j = 1; j <= i; j++){
            for(ll o = i; o <= k; o++){
                for(ll p = 1; p <= o; p++){
                    if((b[i][j] & b[o][p]) == 0) ok[i][j][o][p] = 1;
                }
            }
        }
    }
    ll x = 1;
    for(ll i = 1; i <= k; i++){
        x *= i;
    }
    for(ll i = 0; i < x; i++){
        ll y = i;
        for(ll j = 1; j <= k; j++){
            d[j] = y % j + 1;
            y /= j;
        }
        bool f = 1;
        for(ll j = 1; j <= k; j++){
            if(oo[j][d[j]]) f = 0;
            for(ll o = j + 1; o <= k; o++){
                if(!ok[j][d[j]][o][d[o]]) f = 0;
            }
        }
        if(f) ans++;
    }
    cout << ans;

    return 0;
}