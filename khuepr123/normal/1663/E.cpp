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

char c[300][300];

int xx[] = {-1, 0, -1};
int yy[] = {0, -1, -1};

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string sus = "theseus";
    reverse(all(sus));
    memset(c, 0, sizeof(c));
    for1(i, 101, n + 100) for1(j, 101, n + 100) cin >> c[i][j];
    for1(i, 101, n + 100) for1(j, 101, n + 100){
        x = i; y = j;
        bool saved = 1;
        int ass = 0;
        for1(id, 0, 2){
            string cman;
            saved = 1;
            for1(nm, 0, 6){
                char cac = c[x + xx[id] * nm][y + yy[id] * nm];
                if(cac != sus[nm]) saved = 0;
                // cout << c[x + xx[nm]][y + yy[nm]] << endl;
                // if(x == 101 && y == 102 && saved == 0){
                //     cout << cac;
                // }
            }
            if(saved == 1){
                ass = id; break;
            }
            // cout << endl;
        }
        if(saved){
            // cout << x << " " << y << " " << ass << endl;
            cout << "YES\n"; return 0;
        }
    }
    cout << "NO\n";
}