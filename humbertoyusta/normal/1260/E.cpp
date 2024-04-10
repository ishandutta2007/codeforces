#include<bits/stdc++.h>
#define int long long
#define maxn (1<<18)+5
#define inf 10000000000000007ll
#define f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int dp[maxn][18], a[maxn], n;

main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n;

    for(int i=0; i<=n+1; i++)
        fill( dp[i] , dp[i] + 18 , inf );

    for(int i=1; i<=n; i++)
        cin >> a[i];

    if( a[n] == -1 ){
        cout << 0 << '\n';
        return 0;
    }

    for(int i=1; i<=n; i++)
        dp[i][0] = a[n];

    int ac = 1;
    for(int i=1; i<=lg2(n); i++){
        ac += ( 1 << ( lg2(n) - i ) );
        for(int j=n; j>=1; j--){
            if( n - j < i || n - j >= ac ){
                dp[j][i] = inf;
                continue;
            }
            dp[j][i] = dp[j+1][i-1] + a[j];
            if( a[j] == -1 ){
                cout << dp[j][i] + 1 << '\n';
                return 0;
            }
        }
        for(int j=n-1; j>=1; j--)
            dp[j][i] = min( dp[j][i] , dp[j+1][i] );
    }

    return 0;
}