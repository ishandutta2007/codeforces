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
const ll mod = 998244353;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int dp[maxN];

int fac[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    memset(fac, 0, sizeof(fac));
    for1(i, 1, maxN - 1){
        for(int j = i; j < maxN; j += i){
            fac[j]++;
        }
    }
    int sam = 0;
    for1(i, 1, n){
        dp[i] = sam + fac[i];
        sam = (sam + dp[i]) % mod;
    }
    cout << (dp[n] % mod + mod) % mod << endl;
}