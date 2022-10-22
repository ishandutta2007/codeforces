/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
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
int nx[maxN];
int ftree[maxN];
int pre[maxN];
int ans[maxN];
vector<ii> qr[maxN];
map<int, int> mp;

void xrpre(int num, int plc){
    while(plc <= n){
        ftree[plc] ^= num;
        plc += (plc & (-plc));
        if(!plc) exit(0);
    }
}

int take(int plc){
    int res = 0;
    while(plc){
        res ^= ftree[plc];
        plc -= (plc & (-plc));
    }
    return res;
}

int range(int lll, int rrr){
    return (take(rrr) ^ take(lll - 1) ^ pre[rrr] ^ pre[lll - 1]);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(ftree, 0, sizeof(ftree));
    int o; cin >> n;
    pre[0] = 0;
    for1(i, 1, n){
        cin >> a[i];
        nx[i] = n + 1;
        pre[i] = pre[i - 1] ^ a[i];
        if(mp.find(a[i]) == mp.end()) xrpre(a[i], i);
        else nx[mp[a[i]]] = i;
        mp[a[i]] = i;
    } cin >> o;
    for1(i, 1, o){
        cin >> x >> y;
        qr[x].pb(ii(y, i));
    }
    nx[0] = 1;
    a[0] = 0;
    for1(i, 1, n){
        xrpre(a[i - 1], nx[i - 1]);
        for(ii child : qr[i]){
            ans[child.se] = range(i, child.fi);
        }
    }
    for1(i, 1, o){
        cout << ans[i] << endl;
    }
}