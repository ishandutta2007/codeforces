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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<char> stk;
    stk.pb(127);
    cin >> y >> n >> k;
    for1(i, 1, y * n){
        char c; cin >> c; stk.pb(c);
    }
    vector<string> vcl;
    while(y--) vcl.pb("");
    sort(all(stk), greater<char>());
    for1(i, 1, n){
        vector<char> fut;
        for2(i, k - 1, 0){
            fut.pb(stk.back());
            vcl[i] += stk.back();
            stk.pop_back();
        }
        for2(i, (int)fut.size() - 2, 0){
            if(fut[i] != fut[i + 1]){
                k = k - i - 1; break;
            }
        }
    }
    for(string &ss : vcl){
        while(ss.size() != n){
            ss += stk.back(); stk.pop_back();
        }
    }
    sort(all(vcl));
    for(string ss : vcl) cout << ss << endl;
}