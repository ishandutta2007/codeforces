#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

long long a[maxn],n,dp[maxn],mx[maxn],u,len;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> u;
        a[u]++;
        len=max(len,u);
    }

    dp[1]=a[1], mx[1]=a[1];
    for(int i=2; i<=len+1; i++){
        dp[i] = mx[i-2] + a[i] * i;
        mx[i] = max( mx[i-1] , dp[i] );
        ///if(i==5000) cout << mx[i] << ' ';
    }

    cout << max( dp[len] , dp[len+1] );

    return 0;
}