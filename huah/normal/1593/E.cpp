#include<bits/stdc++.h>
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
const int N=5e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int n,k,d[N];
bool del[N];
vector<int>e[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,k);
        int ans=n;
        rep(i,1,n) del[i]=d[i]=0,e[i].clear();
        rep(i,1,n-1)
        {
            int u,v;sc(u,v);e[u].push_back(v);e[v].push_back(u);d[u]++;d[v]++;
        }
        queue<int>q[2];
        int u=0;
        rep(i,1,n) 
            if(d[i]<=1) q[u].push(i),del[i]=true;
        while(k--)
        {
            if(q[u].empty()) break;
            ans-=q[u].size();
            while(!q[u].empty())
            {
                int x=q[u].front();q[u].pop();
                for(int v:e[x])
                {
                    d[v]--;
                    if(d[v]<=1&&!del[v])
                        q[u^1].push(v),del[v]=true;
                }
            }
            u^=1;
        }
        while(!q[u].empty()) q[u].pop();
        out(ans);
    }
}