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
int n;
int x, y, z, k;

vector<int> a[10];

struct ele{
    int tot; vector<int> vc;
    ele(vector<int> &fl){
        vc = fl;
        tot = 0; for1(i, 0, n - 1) tot += a[i][vc[i]];
    }
    bool operator < (const ele &oth) const{
        return tot < oth.tot;
    }
};

set<vector<int>> st;
set<vector<int>> banned;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<ele> pq;
    cin >> n;
    vector<int> standard;
    for1(i, 0, n - 1){
        cin >> x; a[i].pb(-mod);
        standard.pb(x);
        while(x--){
            cin >> y; a[i].pb(y);
        }
    }
    pq.push(standard);
    int o; cin >> o; while(o--){
        standard.clear();
        for1(i, 1, n){
            cin >> x; standard.pb(x);
        }
        pq.push(standard);
        banned.insert(standard);
    }
    while(1){
        standard = (pq.top()).vc; pq.pop();
        if(st.find(standard) != st.end()) continue;
        if(banned.find(standard) == banned.end()){
            for(int cc : standard) cout << cc << " "; cout << endl;
            exit(0);
        }
        st.insert(standard);
        for(int &cc : standard){
            --cc; pq.push(standard);
            ++cc;
        }
    }
}