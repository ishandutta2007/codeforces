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

void solve(){

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){

    cin >> n;
    vector<int> fl;
    for1(i, 1, n){
        cin >> x;
        if(x % 2) fl.pb(i);
    }
    int st = 2;
    int res = oo;
    if(abs((int)(fl.size()) * 2 - n) > 1) cout << "-1\n";
    else{
        if(n % 2 == 1 && fl.size() * 2 > n){
            st = 1;
        }
        st -= 2;
        int ans;
        ans = 0;
        for(int cc : fl){
            st += 2;
            ans += abs(cc - st);
        }
        res = min(res, ans);
        if(n % 2 == 0){
            st = -1;
            ans = 0;
        for(int cc : fl){
            st += 2;
            ans += abs(cc - st);
        }
        res = min(res, ans);
        }
        cout << res << endl;
    }
    }
}