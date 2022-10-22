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

bool coke(int i, int j){
    return(i == 1 || i == n || j == 1 || j == n);
}

int xx[4], yy[4];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 0, 3) cin >> xx[i] >> yy[i];
        bool fc = 1;
        for1(i, 0, 2) if(!coke(xx[i], yy[i])) fc = 0;
        if(fc){
            for1(i, 0, 2){
                if(xx[i] == 1 || xx[i] == n){
                    if(yy[i] == 1 || yy[i] == n){
                        if(xx[3] == xx[i] || yy[3] == yy[i])
                            fc = 0;
                    }
                }
            }
        }
        set<ii> st;
        for1(i, 0, 3) st.insert(ii(xx[i] % 2, yy[i] % 2));
        if(st.size() == 4) fc = 1;
        cout << (fc ? "NO" : "YES") << endl;
    }
}