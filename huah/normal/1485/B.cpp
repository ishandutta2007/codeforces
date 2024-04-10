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
int n,q,k,a[N];
ll b[N];
int main()
{
    sc(n,q,k);
    rep(i,1,n) sc(a[i]);
    rep(i,2,n-1) b[i]=a[i+1]-a[i-1]-2;
    rep(i,1,n) b[i]+=b[i-1];
    while(q--)
    {
        int l,r;sc(l,r);
        if(l==r) out(k-1);
        else
        {
            ll ans=b[r-1]-b[l];
            ans+=a[l+1]-2;
            ans+=k-a[r-1]-1;
            out(ans);
        }
    }
}