#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 2e2+1, base = 1e9+7;
    int dp[maxn][maxn][1001];
int main()
{
    int n , k;
    int a[maxn];
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);

    sort(a,a+n);
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    for (int pos=1;pos<n;pos++)
        for (int op=0;op<n;op++)
            for (int bl=0;bl<=1000;bl++)
    {
            int new_k=bl+op*(a[pos]-a[pos-1]);
            if (new_k<=k){
                dp[pos][op][new_k] +=(1LL*(op+1)*dp[pos-1][op][bl]%base)%base;
                dp[pos][op][new_k]%=base;
                dp[pos][op-1][new_k] += (1LL*op*dp[pos-1][op][bl]%base) %base;
                dp[pos][op-1][new_k]%=base;
                dp[pos][op+1][new_k] += (1LL*dp[pos-1][op][bl]%base)%base;
                dp[pos][op+1][new_k]%=base;
            }
    }
    ll ans = 0;
    for (int i=0;i<=k;i++)
        {
            ans+=(dp[n-1][0][i])%base;
            ans%=base;
    }
    cout<<ans;
	return 0;
}