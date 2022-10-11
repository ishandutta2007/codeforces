//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e3 + 100;
const ll maxm = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, q, d[maxn][maxn];
pll e[maxm];
bool ans[maxm];
vector<pair<pll, pll> > vec[maxm];

int main(){
    fast_io;

    cin >> n >> m >> q;
    for(ll i = 1; i <= n; i++){
        fill(d[i], d[i] + n + 1, inf);
    }
    for(ll i = 1; i <= m; i++){
        cin >> e[i].F >> e[i].S;
    }
    for(ll i = 0; i < q; i++){
        ll v, u, x, y;
        cin >> x >> y >> v >> u;
        vec[x].pb(Mp(Mp(v, u), Mp(y, i)));
    }
    for(ll i = m; i > 0; i--){
        ll v = e[i].F;
        ll u = e[i].S;
        ll x, y;
        d[v][u] = d[u][v] = i;
        for(ll j = 1; j <= n; j++){
            x = max(i, d[v][j]);
            y = max(i, d[u][j]);
            d[u][j] = min(d[u][j], x);
            d[v][j] = min(d[v][j], y);
        }
        for(ll j = 0; j < (ll)vec[i].size(); j++){
            if(d[vec[i][j].F.F][vec[i][j].F.S] <= vec[i][j].S.F) ans[vec[i][j].S.S] = 1;
        }
    }
    for(ll i = 0; i < q; i++){
        cout << (ans[i] ? "Yes\n" : "No\n");
    }

    return 0;
}