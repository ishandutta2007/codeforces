//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll cmod = 4;
const ll mod[cmod] = {1000000007, 1000000009, 999999137, 1000009559};
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, a[maxn], p[maxn][cmod], c[maxn], h[cmod], d[maxn], ans;
pll b[maxn];
map<pll, ll> cnt;
vector<ll> g[maxn];

int main(){
    fast_io;

    fill(p[0], p[0] + cmod, 1);
    for(ll i = 1; i < maxn; i++){
        for(ll j = 0; j < cmod; j++){
            p[i][j] = p[i - 1][j] * 3 % mod[j];
        }
    }

    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        a[i]--;
        g[a[i]].pb(i);
        if(c[a[i]] == 2){
            for(ll j = 0; j < cmod; j++){
                h[j] = (h[j] - p[a[i]][j] - p[a[i]][j]) % mod[j];
            }
            c[a[i]] = 0;
        }
        else{
            for(ll j = 0; j < cmod; j++){
                h[j] = (h[j] + p[a[i]][j]) % mod[j];
            }
            c[a[i]]++;
        }
        for(ll j = 0; j < cmod; j++){
            if(h[j] < 0) h[j] += mod[j];
        }
        b[i] = Mp(h[1] * mod[0] + h[0], h[3] * mod[2] + h[2]);
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 3; j < (ll)g[i].size(); j++){
            d[g[i][j]] = g[i][j - 3];
        }
    }
    ll ptr = 0;
    cnt[b[0]]++;
    for(ll i = 1; i <= n; i++){
        while(ptr < d[i]){
            cnt[b[ptr]]--;
            ptr++;
        }
        ans += cnt[b[i]];
        cnt[b[i]]++;
    }
    cout << ans;

    return 0;
}