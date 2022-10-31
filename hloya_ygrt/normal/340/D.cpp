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
const int maxn = 1e5+500, base = 1e9+7;//, C = (1 << 30) - 1;
    int t[maxn]={0};
    int dp[maxn];
int get_max(int r)
{
    int ans = 0;
    for (int r1=r;r1>0;r1-=(r1&(-r1))){
        ans = max(ans,t[r1]);
    }
    return ans;
}

    int n;
void update(int i,int x)
{

    while (i<=n){
        t[i] = max(t[i],x);
        i += (i&(-i));
    }
}
int main()
{
  //  files1;
    fast_io;

    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if (i==0){
            dp[i] = 1;
        } else
        {
            dp[i] = get_max(a-1)+1;
        }
        update(a,dp[i]);
    }
    int ans = 0;
    for (int i=0;i<=n;i++)
        ans = max(ans,dp[i]);
    cout<<ans;
	return 0;
}