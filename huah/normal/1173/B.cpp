#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,x[N],y[N];
bool solve(int m,int opt)
{
    if(2*m-1<n) return false;
    if(opt==1)
    {
        for(int i=1;i<=min(n,m);i++)
            printf("%d %d\n",1,i);
        int x=1,y=m;
        for(int i=1;i<=n-m;i++)
        {
            x++;
            printf("%d %d\n",x,y);
        }
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    int l=1,r=1000000,ans;
    while(l<=r)
    {
        int m=l+r>>1;
        if(solve(m,0)) r=m-1,ans=m;
        else l=m+1;
    }
    printf("%d\n",ans);
    solve(ans,1);
}