#include<bits/stdc++.h>
#define maxn 110
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

ll n, m, dp[maxn][maxn], ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> m;
    cin >> s;
    s = '$' + s;

    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=j-1; k>=0; k--){
                dp[i][j] += dp[i-1][k];
                if( dp[i][j] >= m )
                    dp[i][j] = m;
                if( s[k] == s[j] ) break;
            }
        }
    }

    for(int i=n; i>=0; i--)
        for(int j=0; j<=n; j++){
            int take = min( dp[i][j] , m );
            ans += take * ( n - i );
            m -= take;
            if( m == 0 ){
                cout << ans << '\n';
                return 0;
            }
        }

    cout << -1 << '\n';
    return 0;
}