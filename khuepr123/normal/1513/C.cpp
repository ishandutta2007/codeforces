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
const ll mod = 1e9 + 7;
const int maxN = 200025;
const ll oo = 1e18 + 7;
int n, a[maxN], m;
int x, y, z, k;
int dp[maxN];

int calc(int i){
    if(dp[i] != -1) return dp[i];
    dp[i] = calc(i - 9) + calc(i - 10);
    dp[i] %= mod;
    return dp[i];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    for(int i = 0; i < maxN; i++){
        dp[i] = -1;
    }
    for(int i = 0; i < 10; i++){
        dp[i] = 1;
    }
    while(o--){
        cin >> n >> m;
        int ans = 0;
        while(n){
            ans += calc((n % 10) + m);
            n = n / 10;
            ans %= mod;
        }
        cout << (((ans % mod) + mod) % mod) << endl;
    }
}