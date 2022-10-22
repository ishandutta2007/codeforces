#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int prefac[maxN];
int b[maxN];
int c[maxN];
int cnt = 0;
int ans = 0;
int m;

void solve(){
    int mn = 0;
    b[0] = 0;
    for1(i, 1, cnt){
        b[i] -= k;
        b[i] += b[i - 1];
    }
    c[cnt + 1] = 0 - oo;
    for1(i, 0, cnt - 1){
        mn = min(mn, b[i]);
        ans = max(ans, b[i] - mn + c[i + 1] - k);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    prefac[0] = 0;
    a[0] = 0 - mod;
    for1(i, 1, n){
        cin >> a[i];
        prefac[i] = prefac[i - 1] + a[i];
    }
    for1(i, n + 1, maxN - 1){
        a[i] = 0 - mod;
    }
    for1(i, 1, min(m, n)){
        cnt = 0;
        for(int j = i; j <= n; j += m){
            ++cnt;
            b[cnt] = prefac[j + m - 1] - prefac[j - 1];
            int as = 0;
            c[cnt] = 0;
            for1(g, j, j + m - 1){
                as += a[g];
                c[cnt] = max(c[cnt], as);
            }
        }
        solve();
    }
    cout << ans << endl;
}