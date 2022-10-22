/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod[] = {(int)1e9 + 7, (int)1e9 + 9,
 (int)1e9 + 21, (int)1e9 + 33};
int coef = 1000003;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int arr[maxN];
const int lim = 32768;

map<ii, int> mp1;
map<ii, int> mp2;

// target: mp1
void solve(bool downvote){
    for1(ds, 0, lim - 1){
        int rs[] = {0, 0, 0, 0};
        y = __builtin_popcount(arr[1] ^ ds);
        for1(i, 1, n){
            x = __builtin_popcount(arr[i] ^ ds) - y;
            if(downvote) x = 0 - x;
            for1(j, 0, 3){
                rs[j] = (rs[j] * coef + x) % mod[j];
                if(rs[j] < 0) rs[j] += mod[j];
            }
        }
        x = rs[0] + mod[1] + rs[1];
        y = rs[2] + mod[3] + rs[3];
        mp1[ii(x, y)] = ds;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
    }
    for1(i, 1, n){
        arr[i] = a[i] % lim;
    }
    solve(0);
    swap(mp1, mp2);
    for1(i, 1, n){
        arr[i] = a[i] / lim;
    }
    solve(1);
    for(auto child : mp1){
        ii gg = child.fi;
        if(mp2.find(gg) != mp2.end()){
            cout << mp1[gg] * lim + mp2[gg] << endl;
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}