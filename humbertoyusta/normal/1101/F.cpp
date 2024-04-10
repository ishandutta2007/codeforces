/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 404
#define MAXN 250005
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

struct trucks{
    int l,r,w;
};

int n,m,dp[2][maxn][maxn],a[maxn];
long long ans;
vector<trucks> truck[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=m; i++){
        int aa,bb,cc,dd;
        cin >> aa >> bb >> cc >> dd;
        truck[dd].push_back(trucks{aa,bb,cc});
    }

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            dp[0][i][j] = a[j] - a[i];

    for(auto i : truck[0]){
        ans = max( ans , ll(dp[0][i.l][i.r]) * ll(i.w) );
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            fill(dp[i%2][j],dp[i%2][j]+n+1,inf);
            int mn = inf;
            int l = j;
            for(int k=j+1; k<=n; k++){
                while( max( dp[!(i%2)][j][l] , a[k] - a[l] ) >= max( dp[!(i%2)][j][l+1] , a[k] - a[l+1] ) ) l++;
                dp[i%2][j][k] = min( dp[i%2][j][k] , max( dp[!(i%2)][j][l] , a[k] - a[l] ) );
            }
        }/**
        for(int j=1; j<=n; j++)
            for(int k=i+1; k<=n; k++)
                cout << i << ' ' << j << ' ' << k << ' ' << dp[i%2][j][k] << '\n';
*/
        for(auto j : truck[i]){
            ans = max( ans , ll(dp[i%2][j.l][j.r]) * ll(j.w) );
        }
    }

    cout << ans << '\n';

    return 0;
}