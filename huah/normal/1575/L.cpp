#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e5+5,mod=1e9+7;
int n,a[N],hs[N];
#define inf 0x3f3f3f3f
struct node
{
    int x,y;
    bool flag;
    bool operator<(const node&o)const
    {
        if(x!=o.x) return x<o.x;
        return y>o.y;
    }
}b[N];
int dp[N],bit[N];
void add(int x,int v)
{
    while(x<=n) bit[x]=max(bit[x],v),x+=x&-x;
}
int query(int x)
{
    int ans=-inf;
    while(x) ans=max(ans,bit[x]),x-=x&-x;
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i].x=a[i],b[i].y=a[i]-i,hs[i]=a[i]-i,b[i].flag=i>=a[i];
    sort(hs+1,hs+1+n);
    sort(b+1,b+1+n);
    rep(i,1,n) b[i].y=lower_bound(hs+1,hs+1+n,b[i].y)-hs,b[i].y=n-b[i].y+1;
    int ans=0;
    rep(i,1,n) bit[i]=-inf;
    rep(i,1,n)
    {
        int j=i;
        while(j<n&&b[j+1].x==b[i].x) j++;
        rep(k,i,j)
        {
            dp[k]=query(b[k].y)+1;
            if(b[k].flag) dp[k]=max(dp[k],1);
            ans=max(ans,dp[k]);
        }
        rep(k,i,j) add(b[k].y,dp[k]);
        i=j;
    }
    // rep(i,1,n)
    //     printf("%d %d\n",b[i].x,b[i].y);
    printf("%d\n",ans);
}
/*
dp[i]=max(dp[j])
1. aj<ai
2. aj+i-j>=ai
   aj-j>=ai-i
3. j>i
if aj<ai and j>i the aj-j<ai-i
*/