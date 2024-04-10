/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
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

int qry(int vx, int vy){
    cout << "? " << vx << " " << vy << endl;
    cin >> vx; return vx;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        // step 1: find meaningful point
        int l = 1, r = n;
        while(l != r){
            int mid = (l + r) / 2;
            if(qry(1, mid) < 1) l = mid + 1;
            else r = mid;
        }
        --l;// l start
        int valx = qry(l, n) - qry(l + 1, n);
        r = l + valx + 1;
        vector<int> chim;
        chim.pb(l);
        chim.pb(r);
        l = r;
        valx = qry(l, n) - qry(l + 1, n);
        chim.pb(l + valx);
        cout << "! ";
        for(int cc : chim) cout << cc << " ";
        cout << endl;
    }
}