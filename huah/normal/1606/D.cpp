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
const int N=1e5+5,mod=998244353,bs=320;
#define inf 0x3f3f3f3f
int n,m;
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,m);
        pair<int,int>a[m+1][n+1];
        vector<int>f(n+1);
        bool ok[m+1][n+1],okk[m+1][n+1];
        int mx[m+1][n+1],mn[m+1][n+1];
        memset(mx,0,sizeof(mx));
        memset(mn,0,sizeof(mn));
        memset(ok,false,sizeof(ok));
        memset(okk,false,sizeof(okk));
        rep(i,1,n)
            rep(j,1,m) sc(a[j][i].first),a[j][i].second=i;
        rep(j,1,m) sort(a[j]+1,a[j]+1+n);
        rep(i,1,n) f[a[1][i].second]=i;
        for(int j=1;j<m;j++)
        {
            vector<int>b(n+1);
            rep(i,1,n)
            {
                mx[j][i]=mn[j][i]=a[j][i].first;
                if(j>1) mx[j][i]=max(mx[j][i],mx[j-1][i]),mn[j][i]=min(mn[j][i],mn[j-1][i]);
            }
            for(int i=1;i<n;i++)
            {
                b[i]=max(b[i-1],f[a[j][i].second]);
                if(b[i]==i&&a[j][i].first<a[j][i+1].first&&mx[j][i]<mn[j][i+1]&&(j==1||ok[j-1][i]))
                    ok[j][i]=true;
            }
        }
        memset(mx,0,sizeof(mx));
        memset(mn,0,sizeof(mn));
        bool flag=true;
        for(int j=m;j>1&&flag;j--)
        {
            vector<int>b(n+1);
            reverse(a[j]+1,a[j]+1+n);
            rep(i,1,n)
            {
                mx[j][i]=mn[j][i]=a[j][i].first;
                if(j<m) mx[j][i]=max(mx[j][i],mx[j+1][i]),mn[j][i]=min(mn[j][i],mn[j+1][i]);
            }
            for(int i=1;i<n&&flag;i++)
            {
                b[i]=max(b[i-1],f[a[j][i].second]);
                if(b[i]==i&&a[j][i].first>a[j][i+1].first&&mn[j][i]>mx[j][i+1]&&(j==m||okk[j+1][i]))
                {
                    okk[j][i]=true;
                    if(ok[j-1][i])
                    {
                        printf("YES\n");
                        flag=false;
                        vector<bool>ans(n+1);
                        for(int k=1;k<=i;k++)
                            ans[a[1][k].second]=true;
                        rep(i,1,n)
                            printf(ans[i]?"B":"R");
                        printf(" %d\n",j-1);
                    }
                }
            }
        }
        if(flag) printf("NO\n");
    }
}