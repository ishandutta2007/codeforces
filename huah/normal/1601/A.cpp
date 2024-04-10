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
const int N=2e5+5,mod=1e9+7;
int n,a[N];
int main()
{
    // freopen("1.in","r",stdin);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) sc(a[i]);
        int vis[30];memset(vis,0,sizeof(vis));
        rep(i,1,n)
            rep(j,0,29)
            if(a[i]>>j&1) vis[j]++;
        vector<int>ans;
        rep(i,1,n)
        {
            bool flag=true;
            rep(j,0,29)
                if(vis[j]%i) flag=false;
            if(flag) ans.push_back(i);
        }
        for(int i=0;i<ans.size();i++)
            printf(i==ans.size()-1?"%d\n":"%d ",ans[i]);
    }
}