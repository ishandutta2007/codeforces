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
const int N=2e5+5,mod=1e9+7;
int n;
char s[N];
bool del[N];
vector<int>v,res;
ll cal()
{
    int pos=1;
    ll ans=0;
    int sum=0;
    rep(i,1,n) del[i]=false;
    for(char c:v)
    {
        int id=0,now=0;
        rep(i,1,n)
        if(!del[i])
        {
            id++;
            if(s[i]==c)
            {
                del[i]=true;
                now++;
                ans+=id+sum-(pos++);
            }
        }
        sum+=now;
    }
    return ans;
}
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(s+1);
        n=strlen(s+1);
        int vis[26];
        memset(vis,false,sizeof(vis));
        v.clear();
        for(int i=1;i<=n;i++)
        {
            if(!vis[s[i]-'A']) v.push_back(s[i]);
            vis[s[i]-'A']++;
        }
        sort(v.begin(),v.end());
        ll ans=-998;
        while(true)
        {
            ll now=cal();
            if(now>ans) ans=now,res=v;
            if(!next_permutation(v.begin(),v.end())) break;
        }
        for(char c:res)
        {
            while(vis[c-'A']--)
                putchar(c);
        }
        putchar('\n');
    }
}