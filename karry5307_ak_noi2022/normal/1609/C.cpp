#include<bits/stdc++.h>
using namespace std;
int t,n,x,a[200005],nxt1[200005],nxt2[200005];

int P[1000005],cnt;
bool NotP[1000005];
const int Maxn=1e6;
void InitPrime()
{
    for(int i=2;i<=1e6;i++)
    {
        if(!NotP[i]) P[++cnt]=i;
        for(int j=1;j<=cnt && i*P[j]<=Maxn;j++)
        {
            NotP[i*P[j]]=true;
        }
    }
}
int main()
{
    InitPrime();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            nxt1[i]=nxt2[i]=0;
        }
        long long ans=0;
        for(int i=n;i>=1;i--)
        {
            if(i+x>n)
            {
                if(a[i]==1) 
                {
                    nxt1[i]=nxt2[i]=i+x;
                }
                else if(NotP[a[i]]) 
                {
                    nxt1[i]=nxt2[i]=i;
                }
                else 
                {
                    nxt1[i]=i;
                    nxt2[i]=i+x;
                }
            }
            else
            {
                if(a[i]==1) 
                {
                    nxt1[i]=nxt1[i+x];
                    nxt2[i]=nxt2[i+x];
                }
                else if(NotP[a[i]]) 
                {
                    nxt1[i]=i;
                    nxt2[i]=i;
                }
                else 
                {
                    nxt1[i]=i;
                    nxt2[i]=nxt1[i+x];
                }
            }
//            printf("nxt1[%d]=%d,nxt2[%d]=%d\n",i,nxt1[i],i,nxt2[i]);
            int tmp=(nxt2[i]-nxt1[i])/x;
            ans+=tmp;
        }
        for(int i=1;i<=n;i++) if(a[i]!=1 && !NotP[a[i]]) ans--;
        printf("%lld\n",ans);
    }
}