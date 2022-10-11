//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, mxf, mnf, mxs, mns, l[maxn], r[maxn];
pll a[maxn];
string s[maxn];
vector<ll> g[maxn];

pll val(ll x){
    ll o = -inf;
    for(ll i = 0; i < maxn; i++){
        o++;
        for(ll j : g[i]){
            o = max(o, j - x);
        }
        l[i] = o;
    }
    o = inf;
    for(ll i = maxn; i--;){
        o--;
        for(ll j : g[i]){
            o = min(o, j + x);
        }
        r[i] = o;
    }
    for(ll i = mxf - x; i <= mnf + x; i++){
        l[i] = max(l[i], mxs - x);
        r[i] = min(r[i], mns + x);
        if(l[i] <= r[i] && (i != 0 || r[i] != 0)) return Mp(i, r[i]);
    }
    return Mp(-1ll, -1ll);
}

int main(){
    fast_io;

    cin >> n;
    mxf = -inf;
    mnf = inf;
    mxs = -inf;
    mns = inf;
    for(ll i = 0; i < n; i++){
        cin >> s[i];
        for(ll j = 0; j < (ll)s[i].size(); j++){
            if(s[i][j] == 'B') a[i].F++;
            else a[i].S++;
        }
        g[a[i].F].pb(a[i].S);
        mxf = max(a[i].F, mxf);
        mnf = min(a[i].F, mnf);
        mxs = max(a[i].S, mxs);
        mns = min(a[i].S, mns);
    }
    if((ll)g[a[0].F].size() == n){
        cout << "0\n" << s[0];
        return 0;
    }
    ll bl = 0, br = 2000000, mid;
    while(br - bl > 1){
        mid = (bl + br) / 2;
        if(val(mid).F != -1) br = mid;
        else bl = mid;
    }
    cout << br << '\n';
    pll p = val(br);
    for(ll i = 0; i < p.F; i++){
        cout << 'B';
    }
    for(ll i = 0; i < p.S; i++){
        cout << 'N';
    }

    return 0;
}