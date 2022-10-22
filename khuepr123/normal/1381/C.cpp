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
// #define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

pair<int, vector<int>> pr[maxN];
vector<ii> ids;
int b[maxN];
int lost;

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int o; cin >> o; while(o--){

    cin >> n >> x >> y;
    y -= x;
    for1(i, 1, n + 1){
        pr[i].fi = 0;
        pr[i].se.clear();
        b[i] = 0;
        a[i] = 0;
    }
    ids.clear();
    for1(i, 1, n){
        cin >> a[i];
        pr[a[i]].fi++;
        pr[a[i]].se.pb(i);
    }
    for1(i, 1, n + 1){
        if(pr[i].fi == 0) lost = i;
    }
    sort(pr + 1, pr + n + 2, greater<pair<int, vector<int>>>());
    int cn1 = 0;
    int cn2 = 0;
    int cur = 1;
    for1(i, 1, y){
        if((pr[cur].se).size() < 1) cur = 1;
        auto &vl = pr[cur].se;
        ids.pb(ii(a[vl.back()], vl.back()));
        vl.pop_back();
        if(cur == 1) cn1++;
        else cn2++;
        ++cur;
    }
    for1(i, 1, n - x - y){
        if(pr[2].se.size() == 0 && cn1 >= cn2) break;
        if(cn1 <= cn2) break;
        if(pr[cur].se.size() < 1) cur = 1;
        auto &vl = pr[cur].se;
        ids.pb(ii(-1, vl.back()));
        vl.pop_back();
        if(cur == 1) cn1++;
        else cn2++;
        ++cur;
    }
    int fl = ids.size();
    // for(ii cc : ids) cout << cc.fi << " " << cc.se << endl;
    sort(ids.begin(), ids.end());
    z = fl / 2;
    for1(i, 0, fl - 1) b[ids[i].se] = ids[(i + z) % fl].fi;
    for1(i, 1, n) if(b[i] == a[i]){
        cout << "NO\n";
        goto dumb;
    }
    cout << "YES\n";
    for1(i, 1, n){
        if(b[i] == -1) cout << lost;
        else if(b[i]) cout << b[i];
        else{
            if(x){
                cout << a[i]; --x;
            }
            else cout << lost;
        }
        cout << " ";
    }
    cout << endl;

    dumb:;}
}