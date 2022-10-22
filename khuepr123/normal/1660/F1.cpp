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
const int maxN = 600005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
 
int ftree[3][maxN];
int ans;
 
int lex;
 
void inc(int *ftree, int plc){
    while(plc < lex){
        ++ftree[plc];
        plc += plc & -plc;
    }
}
 
int take(int *ftree, int plc){
    int res = 0;
    while(plc){
        res += ftree[plc];
        plc -= plc & -plc;
    }
    return res;
}
 
void exec(int nm){
    int *sus = ftree[nm % 3];
    nm /= 3;
    ans += take(sus, nm); inc(sus, nm);
}
 
signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o;cin >> o;
    while(o--){
        cin >> n; ans = 0;
        x = n + 7;
        lex = n * 2 + 8;
        for1(i, 0, 2) for1(j, 0, lex - 1) ftree[i][j] = 0;
        exec(x);
        for1(i, 1, n){
            char c; cin >> c;
            (c == '-') ? (x += 1) : (x -= 1);
            exec(x);
        }
        cout << ans << endl;
    }
}