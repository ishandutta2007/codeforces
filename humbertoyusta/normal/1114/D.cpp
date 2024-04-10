#include<bits/stdc++.h>
#define maxn 5005
#define inf 1000000007
using namespace std;

int n, a[maxn], dp[maxn][maxn], last[maxn], nxt[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++)
        fill( dp[i] , dp[i] + maxn , inf );

    for(int i=1; i<=n; i++){
        cin >> a[i];
        if( a[i] == a[i-1] ) last[i] = last[i-1];
            else last[i] = i - 1;
    }

    for(int i=n; i>0; i--){
        if( a[i] == a[i+1] ) nxt[i] = nxt[i+1];
            else nxt[i] = i + 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int k = j + i - 1;
            if( nxt[j] > k ){
                dp[j][k] = 0;
                continue;
            }
            if( a[j] == a[k] ) dp[j][k] = min( dp[j][k] , dp[nxt[j]][last[k]] + 1 );
            if( a[j] != a[k] ){
                dp[j][k] = min( dp[j][k] , dp[nxt[j]][k] + 1 );
                dp[j][k] = min( dp[j][k] , dp[j][last[k]] + 1 );
            }
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}