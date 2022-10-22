#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int po[100005];
int niz[100005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        niz[i] = x;
        dp[x] = 1;
        for(int j=2; j*j<=x; j++){
            if(x%j == 0){
                dp[x] = max(dp[x], po[j]+1);
                dp[x] = max(dp[x], po[x/j]+1);
            }
        }
        dp[x] = max(dp[x], po[x]+1);
        for(int j=2; j*j<=x; j++){
            if(x%j == 0){
                po[j] = max(po[j], dp[x]);
                po[x/j] = max(po[x/j], dp[x]);
            }
        }
        po[x] = max(po[x], dp[x]);
    }
    int u=1;
    for(int i=0; i<n; i++) u = max(u, dp[niz[i]]);
    cout << u;
    return 0;
}