#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
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
const int N=1e6+5,mod=998244353;
int k,ans[N];
char s[N];
int main()
{
    sc(k);
    scanf("%s",s+1);
    int n=(1<<k)-1;
    reverse(s+1,s+1+n);
    for(int i=n+1;i<=2*(n+1);i++) ans[i]=1;
    for(int i=n;i>=1;i--)
        if(s[i]=='?') ans[i]=ans[i<<1]+ans[i<<1|1];
    else if(s[i]=='1') ans[i]=ans[i<<1];
    else ans[i]=ans[i<<1|1];
    int q;sc(q);
    while(q--)
    {
        int x;char c;
        scanf("%d %c",&x,&c);
        x=n-x+1;
        s[x]=c;
        while(x)
        {
            if(s[x]=='?') ans[x]=ans[x<<1]+ans[x<<1|1];
            else if(s[x]=='1') ans[x]=ans[x<<1];
            else ans[x]=ans[x<<1|1];
            x>>=1;
        }
        out(ans[1]);
    }
}