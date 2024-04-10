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
int n, a[maxN], b[maxN];
int x, y, z, k;

map<int, int> mp;
map<int, int> mp2;
map<int, int> id[maxN];
stack<int> ord;
int las[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i] >> b[i];
        mp[a[i]] = i;
    }
    a[0] = 0; b[0] = 0; mp[0] = 0;
    ord.push(0);
    for(auto cc : mp){
        mp2[cc.se] = cc.fi;
        las[cc.fi] = cc.se;
    }
    for(auto cc : mp2){
        ord.push(cc.se);
    }
    mp.clear();
    for1(i, 0, n){
        id[a[i]][i] = b[i];
    }
    int o; cin >> o; while(o--){
        cin >> k; set<int> st; while(k--){
            cin >> x; st.insert(x);}
        vector<int> flr;
        stack<int> user;
        while(flr.size() < 2){
            user.push(ord.top()); ord.pop();
            if(st.find(user.top()) == st.end()) flr.pb(user.top());
        }
        x = flr[0]; y = flr[1];
        auto pr = (id[x].lower_bound(las[y]));
        cout << x << " " << pr->se << endl;
        while(!user.empty()){
            ord.push(user.top()); user.pop();
        }
    }
}