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

int nxi[maxN];

int ans;
void back(int l, int r, bool isk){
    if(l > r) return;
    ans += isk;
    int dx = nxi[l];
    back(dx + 1, r, 0);
    back(l + 1, dx - 1, 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n; ans = 0;
        vector<int> stk;
        for1(i, 1, n * 2){
            char c; cin >> c; if(c == '(') stk.pb(i);
            else{
                int vl = stk.back(); stk.pop_back();
                nxi[vl] = i;
            }
        }
        back(1, n * 2, 1);
        cout << ans << endl;
    }
}