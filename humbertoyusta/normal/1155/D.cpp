/** Name: Humberto Yusta Gomez
    Pais: Cuba
    Prov: Villa Clara
    Grado: 11no
    Copyright              **/
#include<bits/stdc++.h>
#define maxn 300010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n;
ll dp[maxn][3],ans,x,a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> x;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=1; i<=n; i++){
        dp[i][0] = max( dp[i-1][0] , 0ll ) + a[i];
        dp[i][1] = max( max( dp[i-1][0] , 0ll ) + a[i]*x , max( dp[i-1][1] , 0ll ) + a[i]*x );
        dp[i][2] = max( max( dp[i-1][2] , 0ll ) + a[i] , max( dp[i-1][1] , 0ll ) + a[i] );
        ans = max( max( ans , dp[i][0] ) , max( dp[i][1] , dp[i][2] ) );
    }

    cout << ans << '\n';

    return 0;
}