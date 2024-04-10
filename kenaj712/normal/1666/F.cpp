#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

const int mod = 998244353;
const int nax = 5005;
int a[nax];
int binom[nax][nax];
int cnt[nax];
int suf[nax];
int n;
ll dp[nax][nax];

void prep(){
    binom[0][0] = 1;
    for(int i=1;i<nax;i++){
        binom[i][0] = 1;
        for(int j=1;j<=i;j++){
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
            if(binom[i][j] >= mod) binom[i][j] -= mod;
        }
    }
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    suf[n + 1] = 0;
    for(int i=n;i>=1;i--){
        suf[i] = suf[i + 1] + cnt[i];
    }
    for(int i=1;i<=n+2;i++){
        for(int j=0;j<=n+2;j++){
            dp[i][j] = 0;
        }
    }
    dp[n + 1][0] = 1;
    for(int i=n+1;i>=2;i--){
        for(int j=0;j<=n;j++){
            if(dp[i][j] == 0) continue;
            // grupy >= i, j miejsc specjalnych zabrane
            int sz = cnt[i - 1];
            int freeHoles = max(0, j - 1 + (j == n / 2) - (suf[i] - j));

            // wsadz nowe
            if(j < n / 2 && sz >= 1){
                if(sz - 1 <= freeHoles){
                    dp[i - 1][j + 1] += (dp[i][j] * binom[freeHoles][sz - 1]);
                    dp[i - 1][j + 1] %= mod;
                }
            }

            if(sz <= freeHoles){
                dp[i - 1][j] += (dp[i][j] * binom[freeHoles][sz]);
                dp[i - 1][j] %= mod;
            }

        }
    }

    cout << dp[1][n / 2] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}