#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=1e5+5;
int n,w,sum[55];
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,w);
        memset(sum,0,sizeof(sum));
        rep(i,1,n)
        {
            int x;sc(x);
            rep(j,0,20)
            if(x>>j&1)
            {
                sum[j]++;
                break;
            }
        }
        int ans=0;
        while(n)
        {
            nep(j,30,0)
            if(w>>j&1)
            {
                int x=1;
                nep(k,j,0)
                {
                    if(sum[k]>=x)
                    {
                        sum[k]-=x;
                        n-=x;
                        break;
                    }
                    else x=(x-sum[k])<<1,n-=sum[k],sum[k]=0;
                }
            }
            ans++;
        }
        out(ans);
    }
}