//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, fen[maxn], a[maxn], b[maxn], ans;
vector<ll> g1[maxn], g2[maxn], gp1, gp2;

void upd(ll x, ll y){
    for(x++; x < maxn; x += x & -x){
        fen[x] += y;
    }
    return;
}
ll get(ll x){
    ll y = 0;
    for(x++; x > 0; x -= x & -x){
        y += fen[x];
    }
    return y;
}

int main(){
    fast_io;

    cin >> n >> m;
    ans = 1;
    fill(b, b + maxn, -1);
    fill(a, a + maxn, -1);
    for(ll i = 0; i < n; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        if(y == 0){
            a[x] = z;
        }
        else{
            b[x] = y;
        }
        if(y == 0 && z == 1000000) ans++;
    }
    for(ll i = 0; i < m; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        if(y == 0){
            g1[z].pb(x);
            g2[z].pb(x);
        }
        else{
            g1[y - 1].pb(-x);
            g2[y - 1].pb(-x);
            gp1.pb(x);
            gp2.pb(x);
        }
        if(y == 0 && z == 1000000) ans++;
    }
    for(ll i = 1; i < maxn; i++){
        if(a[i] != -1) upd(0, 1);
        if(a[i] != -1) upd(a[i] + 1, -1);
        for(ll j : g1[i]){
            if(j > 0) ans += get(j);
            else ans -= get(-j);
        }
    }
    for(ll i : gp1){
        ans += get(i);
    }
    fill(fen, fen + maxn, 0);
    for(ll i = 1; i < maxn; i++){
        if(b[i] != -1) upd(b[i], 1);
        for(ll j : g2[i]){
            if(j > 0) ans += get(j);
            else ans -= get(-j);
        }
    }
    for(ll i : gp2){
        ans += get(i);
    }
    cout << ans;

    return 0;
}