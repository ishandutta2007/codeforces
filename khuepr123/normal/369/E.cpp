/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
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
int x, y, z, k, o;

int ftree[maxN];

vector<int> shut[maxN];

void inc(int plc, int val){
    while(plc < maxN){
        ftree[plc] += val;
        plc += plc & -plc;
    }
}

int take(int plc){
    int res = 0;
    while(plc){
        res += ftree[plc];
        plc -= plc & -plc;
    }
    return res;
}

int ans[maxN];
vector<ii> qry[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> o;
    for1(i, 1, n){
        cin >> x >> y;
        shut[x].pb(y);
        inc(y, 1);
    }
    for1(i, 1, o){
        cin >> z; y = 0; while(z--){
            cin >> x; qry[y + 1].pb(ii(x - 1, i));
            // cout << y + 1 << " " << x - 1 << "   ";
            y = x;
        }
        qry[y + 1].pb(ii(maxN - 1, i));
        // cout << endl;
    }
    for1(i, 1, maxN - 1){
        for(ii cc : qry[i]){
            ans[cc.se] += take(cc.fi);
        }
        for(int cc : shut[i]) inc(cc, -1);
    }
    for1(i, 1, o) cout << n - ans[i] << endl;
}