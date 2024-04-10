#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[100005];
ll niz[100005];

ll a, b, h, w;
int n;

int solve(){
    for(int i=0; i<=a; i++) dp[i] = 0;
    dp[min(h, a)] = w;
    if(h >= a && w >= b){
        return 0;
    }
    for(int j=1; j<=min(n, 40); j++){
        for(int i=a; i>=0; i--){
            dp[min(a, i*niz[j])] = max(dp[min(a, i*niz[j])], dp[i]);
            dp[i] = min(b, dp[i]*niz[j]);
        }
        if(dp[a] >= b){
            return j;
        }
    }
    return n+5;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> a >> b >> h >> w >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    sort(niz+1, niz+1+n);
    reverse(niz+1, niz+1+n);
    int k = solve();
    swap(h, w);
    k = min(k, solve());
    if(k == n+5){
        cout << -1;
        return 0;
    }
    cout << k;
    return 0;
}