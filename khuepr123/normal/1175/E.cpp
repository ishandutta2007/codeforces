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
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n; ii a[maxN];
int x, y, z, k;

int spr[maxN][23];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 1, n){
        cin >> a[i].se >> a[i].fi;
    }
    for1(i, 0, maxN - 1){
        spr[i][0] = i;
    }
    sort(a + 1, a + n + 1);
    for1(i, 1, n){
        swap(a[i].fi, a[i].se);
    }
    int limer = maxN - 1;
    a[0].fi = 0;
    a[0].se = 0;
    for2(i, n, 1){
        int preval = a[i].se;
        a[i].se = min(a[i].se, limer);
        limer = min(limer, a[i].fi - 1);
        if(a[i].se < a[i].fi) continue;
        for1(j, a[i].fi, a[i].se){
            spr[j][0] = preval;
        }
    }
    n = 500000;
    for1(i, 0, 21){
        for1(j, 0, n){
            spr[j][i + 1] = spr[spr[j][i]][i];
        }
    }
    // for1(i, 0, 22){
    //     for1(j, 1, 4){
    //         cout << spr[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    while(o--){
        cin >> x >> y;
        if(spr[x][22] < y) cout << "-1\n";
        else{
            int res = 0;
            for2(i, 21, 0){
                if(spr[x][i] < y){
                    res |= (1 << i);
                    x = spr[x][i];
                }
            }
            cout << res + 1 << endl;
        }
    }
}