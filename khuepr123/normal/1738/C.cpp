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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int cn[2];

bool solve(){
    bool caf = ((cn[1] / 2) & 1);
    bool cole = (((cn[1] + 1) / 2) & 1);
    if(cn[0] & 1){
        int vex = cn[1] % 4;
        if(vex == 2) return 0;
        if(vex == 0) return 1;
        if(vex == 1) return 1;
        if(vex == 3) return 1;
    }
    else return !cole;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        cn[0] = 0; cn[1] = 0;
        for1(i, 1, n){
            cin >> x; ++cn[x & 1];
        }
        if(solve()) cout << "Alice";
        else cout << "Bob";
        cout << endl;
    }
}