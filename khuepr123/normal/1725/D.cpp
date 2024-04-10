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

int cn[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, oo){
        int vxi = (i + 1) / 2;
        if(n <= vxi){
            a[i] = n; n = i; break;
        }
        else{
            a[i] = vxi; n -= vxi;
        }
    }
    x = 0;
    for1(i, 1, n){
        // cout << a[i] << " ";
        x += a[i] * i;
    }
    cout << x << endl;
    memset(cn, 0, sizeof(cn));
    for1(i, 1, n){
        ++cn[i - 1];
        if(i - 1 - a[i] * 2 >= 0){
            --cn[i - 1 - a[i] * 2];
        }
        // cout << sta << endl;
    }
    for2(i, maxN - 1, 2){
        cn[i - 2] += cn[i];
    }
    int lvl = 0;
    int mns = 0;
    int o; cin >> o; while(o--){
        cin >> x;
        x -= mns;
        while(x > cn[lvl] * 2 - 1){
            mns += cn[lvl];
            x -= cn[lvl];
            ++lvl;
        }
        int cock = 0;
        while((x % 2) == 0){
            x /= 2;
            ++cock;
        }
        cout << x + cock + lvl << endl;
    }
}