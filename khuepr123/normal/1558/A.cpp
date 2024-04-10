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
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a, b;
int x, y, z, k;

int vl1, vl2;
set<int> st;

void solve(){
    for1(i, 0, x){
        int vi = x - i;
        int j = vl1 - vi;
        int vj = y - j;
        if(i >= 0 && j >= 0 && vi >= 0 && vj >= 0){
            st.insert(i + j);
        }
        // cout << i << " " << j << " " << vi << " " << vj << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> x >> y;
        st.clear();
        vl1 = (x + y) / 2;
        vl2 = (x + y) - vl1;
        solve();
        swap(x, y);
        solve();
        cout << st.size() << endl;
        for(int c : st) cout << c << " ";
        cout << endl;
    }
}