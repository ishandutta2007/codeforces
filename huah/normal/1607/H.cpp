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
const int N=2e5+5,mod=1e6+5;
#define inf 0x3f3f3f3f
int n,a[N],b[N],m[N],c[N];
struct node
{
    int l,r,id;
    bool operator<(const node&o)const
    {
        if(l==o.r) return r<o.r;
        return l<o.l;
    }
};
vector<node>vc[2000005];
int sol(vector<node>&vc)
{
    sort(vc.begin(),vc.end());
    int ans=0;
    for(int i=0;i<vc.size();i++)
    {
        ans++;
        int j=i;
        int l=vc[i].l,r=vc[i].r;
        while(j+1<vc.size()&&max(l,vc[j+1].l)<=min(r,vc[j+1].r))
        {
            l=max(l,vc[j+1].l);
            r=min(r,vc[j+1].r); 
            j++;
        }
        rep(k,i,j)
            c[vc[k].id]=l;
        i=j;
    }
    return ans;
}
vector<int>num;
bool vis[2000005];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) sc(a[i],b[i],m[i]),c[i]=0;
        rep(i,1,n)
        {
            int r=a[i]-(m[i]-min(m[i],b[i]));
            int l=a[i]-min(m[i],a[i]);
            vc[a[i]+b[i]-m[i]].push_back({l,r,i});
            if(!vis[a[i]+b[i]-m[i]])
            {
                vis[a[i]+b[i]-m[i]]=true;
                num.push_back(a[i]+b[i]-m[i]);
            }
        }
        int ans=0;
        for(int x:num)
            ans+=sol(vc[x]);
        out(ans);
        rep(i,1,n)
        {
            int t=a[i]-c[i];
            out(t,m[i]-t);
        }
        for(int x:num) vis[x]=false,vc[x].clear();
        num.clear();
    }
}