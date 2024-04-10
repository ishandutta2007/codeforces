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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=3e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
ll x,y;
bool judge(ll n)
{
    return n%x==y%n;
}
int main()
{
    // freopen("1.in","r",stdin);
    int t;sc(t);
    while(t--)
    {
        sc(x,y);
        // x=rdint(1,500000000)*2;y=rdint(1,500000000)*2;
        if(x>y) out(x+y);
        else
        {
            ll m=y/2+1;
            ll t=m%x;
            ll g=y-m;
            if(g>=x)
            {
                t=(t+(g-(x-1)))%x;
                m+=g-(x-1);
                g=x-1;
            }
            if(t!=g)
            {
                if(t>g)
                {
                    g-=x-t;
                    m+=x-t;
                    t=0;
                }
                m+=(g-t)/2;
            }
            assert(m%x==y%m);
            out(m);
            //(t+s)%x=g-s
        }
    }
}