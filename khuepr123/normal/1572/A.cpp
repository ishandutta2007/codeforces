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

vector<int> vc[maxN];
int cnt[maxN];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            vc[i].clear();
            cnt[i] = 0;
        }
        for1(i, 1, n){
            cin >> y;
            for1(chim, 1, y){
                cin >> x;
                vc[x].pb(i);
                cnt[i]++;
            }
        }
        set<int> st;
        for1(i, 1, n) if(cnt[i] == 0) st.insert(i);
        int ds = 0;
        int ans = 0;
        int fl = n;
        while(!st.empty()){
            --fl;
            auto itr = st.upper_bound(ds);
            if(itr == st.end()){
                ++ans;
                ds = 0;
                itr = st.begin();
            }
            x = *itr;
            st.erase(x);
            ds = x;
            for(int cc : vc[x]){
                cnt[cc]--;
                if(cnt[cc] == 0) st.insert(cc);
            }
        }
        cout << ((fl == 0) ? (ans + 1) : -1) << endl;
    }
}