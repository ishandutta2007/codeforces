#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n, u, m, cnt[maxn], p[maxn], c[maxn], ans;
int dp[505][5005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n*m; i++){
        cin >> u;
        cnt[u]++;
    }

    for(int i=1; i<=n; i++){
        cin >> u;
        p[u]++;
    }

    for(int i=1; i<=m; i++)
        cin >> c[i];

    for(int i=1; i<=100000; i++){

        if( p[i] == 0 ) continue;

        for(int j=1; j<=p[i]; j++){
            for(int k=1; k<=cnt[i]; k++){
                for(int l=k-1; l>=max(0,k-m); l--){
                    dp[j][k] = max( dp[j][k] , dp[j-1][l] + c[k-l] );
                }
            }
        }

        ans += dp[p[i]][cnt[i]];

        for(int j=1; j<=p[i]; j++)
            for(int k=1; k<=cnt[i]; k++)
                dp[j][k] = 0;
    }

    cout << ans << '\n';

    return 0;
}