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
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int b[maxN];
int x, y, z, k;
int tot = 0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
    }
    for1(i, 1, n){
        cin >> b[i];
        tot += (a[i] * b[i]);
    }
    int ans = tot;
    for1(i, 1, n){
        int dif = 0;
        for2(j, i - 1, 1){
            if(i * 2 - j > n) break;
            dif += (a[j] - a[i * 2 - j]) * (b[j] - b[i * 2 - j]);
            ans = max(ans, tot - dif);
        }
        dif = 0;
        for2(j, i - 1, 1){
            if(i * 2 - j - 1 > n) break;
            dif += (a[j] - a[i * 2 - j - 1]) * (b[j] - b[i * 2 - j - 1]);
            ans = max(ans, tot - dif);
        }
    }
    cout << ans << endl;
}