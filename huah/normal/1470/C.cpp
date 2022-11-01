#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,a[N];
int Q(int pos)
{
    while(pos>n) pos-=n;
    printf("? %d\n",pos);
    fflush(stdout);
    int ans;scanf("%d",&ans);
    return ans;
}
void out(int x)
{
    while(x>n) x-=n;
    printf("! %d\n",x);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=300;i++) Q(1);
    if(n<=300)
    {
        for(int i=1;i<=n;i++) a[i]=Q(i);
        for(int i=1;i<=n;i++)
        {
            int l=i-1,r=i+1;
            if(l==0) l=n;
            if(r==n+1) r=1;
            if(a[i]>a[l]&&a[i]<a[r])
            {
                out(i);break;
            }
        }
    }
    else
    {
        int pos=1,block=sqrt(n)-1,l,r;
        for(int i=1;i<=n;i++)
        {
            if(Q(pos)>k)
            {
                l=pos;r=pos-1+n;
                break;
            }
            pos+=block;
            if(pos>n) pos-=n;
        }
        int ans=l;
        while(l<=r)
        {
            int ml=l+(r-l)/3;
            int mr=r-(r-l)/3;
            if(Q(ml)<Q(mr)) ans=ml,r=mr-1;
            else ans=mr,l=ml+1;
        }
        ans++;
        out(ans);
    }
}