#include<bits/stdc++.h>
#define maxn 505
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int n,dp[maxn][maxn];
char s[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w".stdout);

    cin >> n;
    cin >> (s+1);

    for(int i=1; i<=n; i++)
        fill( dp[i] , dp[i] + n + 1 , inf );

    for(int i=1; i<=n; i++){
        dp[i][i] = 1;
        dp[i][i+1] = 2 - ( s[i] == s[i+1] );
    }

    for(int i=3; i<=n; i++){
        for(int j=1; j+i-1<=n; j++){
            int k = j + i - 1;
            for(int l=j; l<k; l++){
                dp[j][k] = min( dp[j][k] , dp[j][l] + dp[l+1][k] - ( s[j] == s[l+1] ) );
            }
        }
    }

    cout << dp[1][n];

    return 0;
}