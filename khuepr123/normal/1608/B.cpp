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

bool offset;


void prt(int nm){
    if(offset) nm = n + 1 - nm;
    cout << nm << " ";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> x >> y; swap(x, y);
        if(abs(x - y) > 1 || x + y > n - 2){
            cout << "-1\n"; continue;
        }
        int l = 1, r = n;
        int role;
        offset = 0;
        if(x == y && y == 0){
            for1(i, 1, n) cout << i << " ";
            cout << endl; continue;
        }
        if(x < y){
            swap(x, y); offset = 1;
        }
        if(x == y){
            cout << "1 "; ++l; --y;
        }
        if(x > y){
            role = 1;
            prt(n); --r;
            while(l <= r){
                // cout << "     " << x << " " << y << "      ";
                if(role){
                    prt(l);
                    ++l;
                    --x;
                }
                else{
                    if(y == 0){
                        for1(i, l, r) prt(i);
                        break;
                    }
                    prt(r);
                    --r;
                    --y;
                }
                role = 1 - role;
            }
        }
        cout << endl;
    }
}