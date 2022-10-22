#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

//bool np[10000005];
int u[10000005];
int kl[10000005];
int a[200005];
int dokle[25][200005];
int dp[200005][25];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] = u[a[i]];
    }
    for(int j=0; j<=k; j++){
        int used = 0;
        int l = 1;
        for(int i=1; i<=n; i++){
            kl[a[i]]++;
            if(kl[a[i]] > 1) used++;
            while(used > j && l < i){
                kl[a[l]]--;
                if(kl[a[l]]) used--;
                l++;
            }
            dokle[j][i] = l;
        }
        for(int i=1; i<=n; i++) kl[a[i]] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = i;
            for(int x=0; x<=j; x++){
                dp[i][j] = min(dp[i][j], 1 + dp[dokle[x][i]-1][j-x]);
            }
        }
    }
    cout << dp[n][k] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=0; i<=10000000; i++) u[i] = i;
    for(int i=2; i*i<=10000000; i++){
        for(int j=i*i; j<=10000000; j+=i*i){
            while(u[j]%(i*i) == 0) u[j] /= i*i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}