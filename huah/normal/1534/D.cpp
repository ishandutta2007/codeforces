#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
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
const int N=2e3+5,mod=1e9+7;
int n,d[N];
bool e[N][N];
vector<int>v[N];
void Q(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    rep(i,1,n) sc(d[i]);
    rep(i,1,n)
        if(d[i]==1) e[i][x]=e[x][i]=true;
}
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n);
    Q(1);
    rep(i,1,n)
        v[d[i]].push_back(i);
    int sum=0;
    for(int i=1;i<=n;i+=2) sum+=v[i].size();
    int s=1;
    if(n-1-sum<sum)
        sum=n-1-sum,s++;
    for(int i=s;i<=n;i+=2)
        for(int x:v[i]) Q(x);
    printf("!\n");
    rep(i,1,n)
        rep(j,i+1,n)
        if(e[i][j])
            printf("%d %d\n",i,j);
    fflush(stdout);
}