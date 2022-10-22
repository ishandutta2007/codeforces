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
int b[maxN];

vector<int> v[2];
vector<int> c[2];

int solve(){
    for1(i, 0, 1) c[i] = v[i];
    sort(all(c[0]));
    sort(all(c[1]));
    if(c[0].empty()) return 0;
    c[0].erase(c[0].begin()); bool f = 0;
    int res = 0;
    while(c[0].size() || c[1].size()){
        f = !f;
        if(c[f].empty()) break;
        res += c[f].back();
        c[f].pop_back();
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        v[0].clear();
        v[1].clear();
        for1(i, 1, n){
            cin >> a[i];
        }
        int sum = 0;
        for1(i, 1, n){
            cin >> x; v[a[i]].pb(x);
            sum += x;
        }
        int ans = solve();
        swap(v[0], v[1]);
        ans = max(ans, solve());
        cout << sum + ans << endl;
    }
}