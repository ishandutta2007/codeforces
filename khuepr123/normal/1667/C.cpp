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

vector<ii> ans;

void ins(int v1, int v2){
    ans.pb(ii(v1, v2));
}

void pout(){
    cout << ans.size() << endl;
    for(ii pr : ans) cout << pr.fi << " " << pr.se << endl;
    exit(0);
}

void solve(vector<int> &v){
    if(v.empty()) return;
    int r = v.size() - 1;
    for1(i, 0, mod){
        if(i == r){
            ins(v[i], v[i]); return;
        }
        if(i > r) return;
        ins(v[i], v[r]);
        ins(v[r], v[i]);
        --r;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n <= 2){
        cout << "1\n";
        cout << "1 1\n";
        exit(0);
    }
    if(n == 3){
        cout << "2\n";
        cout << "1 1\n1 2\n";
        exit(0);
    }
    for1(vol, 1, n) if(vol * 3 >= 2 * n - 1){
        if((vol % 2) == 0){
            ins(vol, vol); --vol;
        }
        vector<int> v1, v2;
        for1(i, 1, vol / 2) v1.pb(i);
        for1(i, vol / 2 + 1, vol) v2.pb(i);
        solve(v1);
        solve(v2);
        pout();
    }
}