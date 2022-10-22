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
int n, a[maxN];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        vector<int> vc;
        vector<ii> id;
        set<int> st;
        for1(i, 1, k){
            cin >> x >> y;
            if(x > y) swap(x, y);
            id.pb(ii(x, y));
            st.insert(x);
            st.insert(y);
        }
        for1(i, 1, n * 2){
            if(st.find(i) == st.end()) vc.pb(i);
        }
        sort(vc.begin(), vc.end());
        k = n - k;
        for1(i, 0, k - 1){
            id.pb(ii(vc[i], vc[i + k]));
        }
        int ans = 0;
        for(ii c1 : id){
            for(ii c2 : id){
                if(c1.fi == c2.fi) continue;
                if(c1.fi < c2.fi && c2.fi < c1.se && c1.se < c2.se)
                    ++ans;
            }
        }
        cout << ans << endl;
    }
}