/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;

ii mx[maxN];
vector<ii> adder[maxN];

struct query{
    int v1, v2, id;
    query(int v1, int v2, int id): v1(v1), v2(v2), id(id) {}
    bool operator < (const query &oth){
        int f1 = v1 / v2;
        int f2 = oth.v1 / oth.v2;
        if(f1 != f2) return f1 < f2;
        return (v1 - (f1 * v2)) * oth.v2 < (oth.v1 - (f1 * oth.v2)) * v2;
    }
};

vector<query> qr;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    memset(mx, -1, sizeof(mx));
    for1(i, 1, n){
        cin >> a[i];
    }
    for1(i, 1, m){
        cin >> z >> x >> y;
        if(z == 1){
            mx[x] = max(mx[x], {y, i});
        }
        if(z == 3){
            qr.pb({y, 1, i + mod});
        }
        if(z == 2){
            adder[x].pb(ii(y, i));
        }
    }
    for1(i, 1, n){
        adder[i].pb(ii(mx[i].fi - a[i], mx[i].se - mod));
        sort(adder[i].begin(), adder[i].end(), greater<ii>());
        if(adder[i].back().fi < 0) adder[i].pop_back();
        x = a[i];
        for(ii cc : adder[i]){
            qr.pb({cc.fi + x, x, cc.se});
            x += cc.fi;
        }
    }
    sort(qr.begin(), qr.end()); reverse(qr.begin(), qr.end());
    k = min(k, (int)qr.size());
    cout << k << endl;
    for1(i, 0, k - 1){
        x = qr[i].id;
        if(x < 0) cout << x + mod << " ";
    }
    for1(i, 0, k - 1){
        x = qr[i].id;
        if(x > 0 && x < mod) cout << x << " ";
    }
    for1(i, 0, k - 1){
        x = qr[i].id;
        if(x > mod) cout << x - mod << " ";
    }

}