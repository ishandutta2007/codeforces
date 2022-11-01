#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define ll long long
using namespace std;
const int maxn = 5e3+20;
    ll a[maxn],pref[maxn];
    ll dp[maxn][maxn];
   // pair<int,int> parent[maxn][maxn];
int main()
{
   // freopen("input.txt","r",stdin);
    int n, m , k;
    scanf("%d %d %d",&n,&m,&k);

    for (int i=0;i<n;i++)
        scanf("%I64d",a+i);
    pref[0] = a[0];
    for (int i=1;i<n;i++)
        pref[i] = pref[i-1] + a[i];

    memset(dp,0,sizeof(dp));

    for (int pos = 0; pos < n;pos++)
    for (int cnt = 0; cnt < k ;cnt++){
        int r = pos + m;
        if (r <=n){
        ll sum = pos ? pref[r-1] - pref[pos-1] : pref[r-1];
        ll ls =dp[r][cnt+1];
        ll rs =dp[pos][cnt] + sum;
        if (rs > ls){
            dp[r][cnt+1] = rs;
           // parent[r][cnt+1] = mp(pos,cnt);
        }
        }
        //dp[r][cnt] = max(dp[r][cnt], dp[pos][cnt]);
        for (int pos1 = pos+1;pos1<=r&&pos1<=n;pos1++)
            dp[pos1][cnt] = max(dp[pos1][cnt], dp[pos][cnt]);
    }
    ll ans = 0;
    for (int i=0;i<=n;i++){
        ans = max(ans, dp[i][k]);
    }
    cout<<ans;
    int sasd;
    return 0;
}