#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;

const int MAXN = 200000;
const int K = 17;

int sled[MAXN+5][K+5];
int pref[MAXN+5][K+5];
int dp[(1<<K)+5];

bool appears(int x, int l, int r){
    int g = pref[r][x];
    if(l > 0) g -= pref[l-1][x];
    return g > 0;
}

bool check(int g){
    for(int i=n; i>n-g; i--){
        for(int j=0; j<k; j++){
            sled[i][j] = n;
        }
    }
    for(int i=n-g; i>=0; i--){
        int sv = 0;
        for(int j=0; j<k; j++){
            sled[i][j] = sled[i+1][j];
            sv += appears(j, i, i+g-1);
        }
        if(sv == 1){
            for(int j=0; j<k; j++){
                if(appears(j, i, i+g-1)) sled[i][j] = i;
            }
        }
        if(sv == 0){
            for(int j=0; j<k; j++) sled[i][j] = i;
        }
    }
    for(int i=1; i<(1<<k); i++) dp[i] = n;
    dp[0] = -1;
    for(int mask=0; mask<(1<<k); mask++){
        if(dp[mask] >= n) continue;
        for(int j=0; j<k; j++){
            if((1<<j) & mask) continue;
            dp[mask | (1<<j)] = min(dp[mask | (1<<j)], sled[dp[mask]+1][j] + g-1);
        }
    }
    return dp[(1<<k)-1] <= n-1;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i) pref[i][j] = pref[i-1][j];
            if(s[i] == 'a' + j) pref[i][j]++;
        }
    }
    int res = 0, l = 1, r = n/k;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
            res = mid;
        }
        else r = mid-1;
    }
    cout << res << "\n";
    return 0;
}