#include<bits/stdc++.h>
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
const int N=2e5+5;
ll sum(ll n)
{
    return n*(n+1)/2;
}
ll sol(int r,int t)
{
    if(r<=t) return sum(r-1);
    else return sum(t-1)+1ll*(r-t)*t;
}
int main()
{
    int t;sc(t);
    while(t--)
    {
        int x,y;sc(x,y);
        y=min(y,x-1);
        if(y==0) out(0);
        else
        {
            ll ans=0;
            for(int l=2,r;l<=y+1;l=r+1)
            {
                r=min(y+1,x/(x/l));
                int t=x/l;
                ans+=sol(r-1,t)-sol(l-2,t);
            }
            out(ans);
        }
    }
}