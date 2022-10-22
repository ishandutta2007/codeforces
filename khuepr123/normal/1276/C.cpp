/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

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
const int maxN = 400005;
const ll oo = 1e18 + 7;
int n;
int x, y, z, k;

map<int, int> mp;
int m = 0;

ii cop[maxN];

vector<int> vc[maxN];

int ans = 0;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; k = 0;
    for1(i, 1, n){
        cin >> x;
        mp[x]++;
    }
    for(auto cc : mp){
        ++m;
        cop[m].fi = cc.se;
        cop[m].se = cc.fi;
    }
    cop[m + 1].fi = 0;
    sort(cop + 1, cop + m + 1, greater<ii>());
    mp.clear();
    int ptr = 1;
    for1(i, 1, (int)sqrt(n)){
        x = 0;
        for1(j, 1, m){
            x += min(cop[j].fi, i);
        }
        x -= (x % i);
        if(x >= i * i){
            if(x > ans){
                ans = x; k = i;
            }
        }
    }
    cout << ans << endl;
    cout << k << " " << ans / k << endl;
    x = 0;
    for1(i, 1, m){
        y = min(k, cop[i].fi);
        while(y--){
            vc[x % k].pb(cop[i].se);
            ++x;
            if(x == ans) goto dumb;
        }
    }
    dumb:;
    ans /= k;
    for1(i, 0, k - 1){
        reverse(vc[i].begin(), vc[i].end());
        for1(j, i, i + ans - 1) cout << vc[i][j % ans] << " ";
        cout << endl;
    }
}