#include<bits/stdc++.h>
#define maxn 212
#define inf 1000000007
#define f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int best(inf);
pair<ii,int> id;
string a, b, ans;
int n, m;
int dp[maxn][maxn][maxn+maxn];
pair<ii,int> p[maxn][maxn][maxn+maxn];

void back_track(int i,int j,int k){
    if( i <= 1 && j <= 1 ){
        for(int i=1; i<k; i++) ans = '(' + ans;
        return;
    }
    if( p[i][j][k].f == (ii){i-1,j-1} ) ans = a[i] + ans;
    if( p[i][j][k].f == (ii){i-1,j} ) ans = a[i] + ans;
    if( p[i][j][k].f == (ii){i,j-1} ) ans = b[j] + ans;
    back_track(p[i][j][k].f.f,p[i][j][k].f.s,p[i][j][k].s);
}

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> a >> b;
    n = a.size(), m = b.size();
    n++, m++;

    a = "&&" + a;
    b = "&&" + b;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            fill( dp[i][j] , dp[i][j] + n + m + 10 , inf );

    for(int i=1; i<=n+m+1; i++)
        dp[1][1][i] = i - 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k<=n+m+1; k++){
                if( i == 1 && j == 1 ) continue;
                if( a[i] == '(' ){
                   if( dp[i][j][k] > dp[i-1][j][k-1] + 1 ){
                        dp[i][j][k] = dp[i-1][j][k-1] + 1;
                        p[i][j][k] = {{i-1,j},k-1};
                   }
                }
                if( a[i] == ')' ){
                   if( dp[i][j][k] > dp[i-1][j][k+1] + 1 ){
                        dp[i][j][k] = dp[i-1][j][k+1] + 1;
                        p[i][j][k] = {{i-1,j},k+1};
                   }
                }
                if( b[j] == '(' ){
                   if( dp[i][j][k] > dp[i][j-1][k-1] + 1 ){
                        dp[i][j][k] = dp[i][j-1][k-1] + 1;
                        p[i][j][k] = {{i,j-1},k-1};
                   }
                }
                if( b[j] == ')' ){
                   if( dp[i][j][k] > dp[i][j-1][k+1] + 1 ){
                        dp[i][j][k] = dp[i][j-1][k+1] + 1;
                        p[i][j][k] = {{i,j-1},k+1};
                   }
                }

                if( ( a[i] == '(' && b[j] == '(' ) && ( dp[i-1][j-1][k-1] + 1 < dp[i][j][k] ) ){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                    p[i][j][k] = {{i-1,j-1},k-1};
                }
                if( ( a[i] == ')' && b[j] == ')' ) && ( dp[i-1][j-1][k+1] + 1 < dp[i][j][k] ) ){
                    dp[i][j][k] = dp[i-1][j-1][k+1] + 1;
                    p[i][j][k] = {{i-1,j-1},k+1};
                }
                if( i == n && j == m ){
                    if( dp[i][j][k] + k - 1 < best ){
                        best = dp[i][j][k] + k - 1;
                        id = { { i , j } , k };
                    }
                }
            }
        }
    }

    back_track(n,m,id.s);
    for(int i=1; i<id.s; i++)
        ans = ans + ')';

    cout << ans << '\n';

    return 0;
}