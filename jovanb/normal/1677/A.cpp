#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 5000;

short ima_p[N+5][N+5];
short ima_s[N+5][N+5];
int a[N+5];

void solve(){
    int n;
    cin >> n;
    for(int i=0; i<=n+2; i++){
        for(int j=0; j<=n+2; j++){
            ima_p[i][j] = 0;
            ima_s[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ima_p[i][j] += ima_p[i-1][j];
            if(a[i] <= j) ima_p[i][j]++;
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){
            ima_s[i][j] += ima_s[i+1][j];
            if(a[i] <= j) ima_s[i][j]++;
        }
    }
    ll res = 0;
    for(int b=1; b<=n; b++){
        for(int c=b+1; c<=n; c++){
            res += 1LL*ima_p[b-1][a[c]-1]*ima_s[c+1][a[b]-1];
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}