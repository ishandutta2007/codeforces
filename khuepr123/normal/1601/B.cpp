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
#define endl "\n"
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

int l = n;
int r;
int b[maxN];

// 2 set: reached and fallen
// reached only get higher; and must be higher than lastrange

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
        a[i] = i - a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;
    // min reachable lowheight
    for1(i, 1, n){
        cin >> b[i];
        b[i] = i + b[i];
        // cout << b[i] << " ";
    }
    // cout << endl;
    // max falldown
    r = a[n];
    l = n;
    vector<int> vl;
    for1(turn, 1, n * 3){
        if(r <= 0){
            cout << turn << endl;
            for(int cc : vl) cout << cc << " ";
            cout << "0";
            return 0;
        }
        int rech = oo;
        int pin = oo;
        for1(i, r, l){
            if(rech > a[b[i]]){
                pin = i;
            }
            rech = min(rech, a[b[i]]);
        }
        vl.pb(pin);
        if(rech >= r || pin == oo) break;
        l = r + 1;
        r = rech;
        // cout << l << " " << r << endl;
    }
    cout << "-1\n";
}