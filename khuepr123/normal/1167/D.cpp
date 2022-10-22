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
const int maxN = 400005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int ans[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; n /= 2;
    stack<int> s;
    bool fl = 0;
    for1(i, 1, n * 2){
        char c; cin >> c;
        if(c == '('){
            s.push(i);
        }
        else{
            fl = (s.size() % 2);
            ans[s.top()] = fl;
            ans[i] = fl;
            s.pop();
        }
    }
    for1(i, 1, n * 2) cout << ans[i];
}