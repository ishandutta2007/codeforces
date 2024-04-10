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
int n;
char s[N];
bool check(int x,string &ans)
{
  string t;
  rep(i,1,x) t+=s[i];
  for(char c:ans)
  {
    string tt;
    for(char cc:t)
      if(cc!=c) tt+=cc;
    t=tt;
    for(int i=0;i<t.size();i++)
      if(t[i]!=s[x+1+i]) return false;
    x+=t.size();
  }
  return true;
}
int main()
{
  // freopen("1.in","r",stdin);
    int t;sc(t);
    while(t--)
    {
      sc(s+1);
      n=strlen(s+1);
      string ans;
      bool vis[26];
      memset(vis,false,sizeof(vis));
      for(int i=n;i>=1;i--)
        if(!vis[s[i]-'a']) vis[s[i]-'a']=true,ans+=s[i];
      reverse(ans.begin(),ans.end());
      int ss[26];
      memset(ss,0,sizeof(ss));
      bool flag=false;
      for(int i=1;i<=n;i++)
      {
        ss[s[i]-'a']++;
        int len=i,sum=i;
        for(char c:ans) sum-=ss[c-'a'],len+=sum;
        if(len==n&&check(i,ans))
        {
          flag=true;
          for(int j=1;j<=i;j++) putchar(s[j]);
          putchar(' ');
          cout<<ans<<'\n';
          break;
        }
      }
      if(!flag) out(-1);
    }
}