/*
time complex:O(n)
*/
#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
int n,a[N],b[N];
char s[N];
void sol(int cas)
{
    sc(n);
    sc(s+1);
    int sum1=0,sum2=0;
    rep(i,1,n)
    {
        if(s[i]=='1') sum1++,sum2++,a[i]=b[i]=1;
        else 
        {
            if(sum1>sum2) a[i]=-1,b[i]=1,sum1--,sum2++;
            else b[i]=-1,a[i]=1,sum1++,sum2--;
        }
        if(sum1<0||sum2<0)
        {
            printf("NO\n");
            return;
        }
    }
    if(sum1!=sum2||sum1%2)
    {
        printf("NO\n");
        return;
    }
    nep(i,n,1)
    {
        if(s[i]=='1'&&sum1)
        {
            sum1-=2;sum2-=2;
            a[i]=b[i]=-1;
        }
    }
    if(sum1)
    {
        printf("NO\n");
        return;
    }
    rep(i,1,n)
    {
        sum1+=a[i];sum2+=b[i];
        if(sum1<0||sum2<0)
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    rep(i,1,n) printf(i==n?"%c\n":"%c",a[i]==-1?')':'(');
    rep(i,1,n) printf(i==n?"%c\n":"%c",b[i]==-1?')':'(');
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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