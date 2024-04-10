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
const int maxn = 1e5+500, base = 1e9+7;
    ll dp[maxn*10];
    int t[maxn*10],a[maxn];

void add(int *t,int i,int x)
{
    while (i<maxn*10)
    {
        t[i]%=base;
        t[i]+=x%base;
        t[i]%=base;
        i+=i&(-i);
    }
}

int sum(int *t ,int r)
{
    int res = 0;
    while (r>0)
    {
            t[r]%=base;
            res+=t[r];
            res%=base;
            r-=r&(-r);
    }
    return res;
}

int main()
{

    //files1;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
         scanf("%d",a+i);
         a[i]*=1;
}
    int ans = 0;
    for (int i=0;i<n;i++){
        int j = a[i];
        dp[j] = 1LL*sum(t,j);
        dp[j]*=j;
        dp[j]%=base;
        dp[j]+=j;
        dp[j]%=base;
        int delta = sum(t,j) - sum(t,j-1);
        //if (delta<0)
       //     return 2;
        add(t,j,dp[j]-delta);
    }
    for (int i=0;i<maxn*10;i++)
        {
            ans+=dp[i];
            ans%=base;
         //   if(ans<0)
          //      return 3;
}
    cout<<ans;

    return 0;
}