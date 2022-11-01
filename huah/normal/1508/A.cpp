#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=3e5+5,mod=1e9+7;
char s[3][N];
int n;
int count(char c,char *s)
{
    int ans=0;
    rep(i,1,2*n) ans+=c==s[i];
    return ans;
}
void sol(int x,int y,int op)
{
    vector<int>v1,v2;
    rep(i,1,2*n)
    {
        if(s[x][i]-'0'==op) v1.push_back(i);
        if(s[y][i]-'0'==op) v2.push_back(i);
    }
    v1.resize(n);
    v2.resize(n);
    int i=1,j=1;
    string ans;
    for(int k=0;k<n;k++)
    {
        int a=v1[k],b=v2[k];
        while(i<a) ans+=s[x][i++];
        while(j<b) ans+=s[y][j++];
        ans+=char(op+'0');
        i++;j++;
    }
    while(i<=2*n) ans+=s[x][i++];
    while(j<=2*n) ans+=s[y][j++];
    assert(ans.size()==3*n);
    cout<<ans<<'\n';
}
void sol(int cas)
{
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,0,2) sc(s[i]+1);
        int x,y,op;
        rep(i,0,2)
            rep(j,i+1,2)
        {
            if(count('0',s[i])>=n&&count('0',s[j])>=n)
                x=i,y=j,op=0;
            if(count('1',s[i])>=n&&count('1',s[j])>=n)
                x=i,y=j,op=1;
        }
        sol(x,y,op);
    }
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  while(t--)
  {    
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/