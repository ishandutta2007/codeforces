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
const int N=1e3+5,mod=998244353;
int n;
ll a[N],b[N];
int main()
{
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) sc(a[i]),b[i]=a[i];
        printf("%d\n",n/2*6);
        for(int i=1;i<=n;i+=2)
        {
            printf("1 %d %d\n",i,i+1);
            a[i]+=a[i+1];
            printf("2 %d %d\n",i,i+1);
            a[i+1]-=a[i];
            printf("1 %d %d\n",i,i+1);
            a[i]+=a[i+1];
            printf("2 %d %d\n",i,i+1);
            a[i+1]-=a[i];
            printf("1 %d %d\n",i,i+1);
            a[i]+=a[i+1];
            printf("2 %d %d\n",i,i+1);
            a[i+1]-=a[i];
        }
        rep(i,1,n) assert(a[i]==-b[i]);
    }
}