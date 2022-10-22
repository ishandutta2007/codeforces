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

string s, t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> s >> t;
        n = s.size();
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        s = '?' + s;
        // cout << s << " " << t << endl;
        int cur = 0;
        for1(i, 1, n){
            if(cur == t.size()) break;
            if(s[i] == t[cur] && ((i - cur) % 2 != 0)) ++cur;
        }
        if(cur == t.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}