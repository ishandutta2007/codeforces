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

int vol;

vector<int> col, row;
// vector<int> col2, row2;

void pout(){
    // assert(!col.empty());
    // assert(!row.empty());
    swap(col, row);
    cout << "1 " << col.size() << " " << row.size() << endl;
    for(int cc : col) cout << cc << " ";
    cout << endl;
    for(int cc : row) cout << cc << " ";
    cout << endl;
    exit(0);
}

int qry(int vx, int vy){
    if(abs(vx) > vol || abs(vy) > vol) pout();
    cout << "0 " << vx << ' ' << vy << endl;
    int res = mod; cin >> res; assert(res != -1); return res;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rang(int le, int ri){
    return rng() % (ri - le + 1) + le;
}

void bicheck(int vl){
    if(!qry(vl, y)) row.pb(vl);
    if(!qry(x, vl)) col.pb(vl);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // col2.pb(2);
    // row2.pb(0);
    // row2.pb(-3);
    vol = (int)1e8;
    while(1){
        x = rang(-vol, vol);
        y = rang(-vol, vol);
        if(qry(x, y)) break;
    }
    z = qry(-vol, -vol) - vol;
    bicheck(z);
    // cout << z << endl;
    while(1){
        int ri = 27, le = 0;
        while(le != ri){
            // cout << le << " " << ri << endl;
            int mid = (le + ri) / 2;
            int pwr = (1 << mid);
            if(z + pwr > vol){
                if(le > mid - 1) pout();
                ri = mid - 1; continue;
            }
            if(qry(z + pwr, z + pwr) != pwr)
                ri = mid;
            else le = mid + 1;
        }
        int mid = le;
        int pwr = (1 << mid);
        int val = qry(z + pwr, z + pwr);
        if(val == pwr) pout();
        z = z + val + pwr; bicheck(z);
        // cout << z << " " << mid << " " << pwr << endl;
    }
    pout();
}