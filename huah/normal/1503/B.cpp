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
void sol(int cas)
{
    int n;sc(n);
    int a[n+1][n+1];
    memset(a,0,sizeof(a));
    vector<pair<int,int>>vc[2];
    rep(i,1,n)
        rep(j,1,n)
        vc[(i+j)&1].push_back({i,j});
    int c0=0,c1=0;
    rep(i,1,n*n)
    {
        int x;sc(x);
        if(!c0&&!c1)
        {
            c0=1;
            if(c0==x) c0++;
            printf("%d %d %d\n",c0,vc[0].back().first,vc[0].back().second);
            vc[0].pop_back();
        }
        else if(!c1)
        {
            c1=1;
            while(c1==x||c1==c0) c1++;
            printf("%d %d %d\n",c1,vc[1].back().first,vc[1].back().second);
            vc[1].pop_back();
        }
        else if(vc[0].size()&&vc[1].size())
        {
            if(x==c0)
            {
                printf("%d %d %d\n",c1,vc[1].back().first,vc[1].back().second);
                vc[1].pop_back();
            }
            else
            {
                printf("%d %d %d\n",c0,vc[0].back().first,vc[0].back().second);
                vc[0].pop_back();
            }
        }
        else if(vc[0].size())
        {
            if(x!=c0)
            {
                printf("%d %d %d\n",c0,vc[0].back().first,vc[0].back().second);
                vc[0].pop_back();
            }
            else
            {
                int y=1;
                while(y==c0||y==c1) y++;
                printf("%d %d %d\n",y,vc[0].back().first,vc[0].back().second);
                vc[0].pop_back();
            }
        }
        else if(vc[1].size())
        {
            if(x!=c1)
            {
                printf("%d %d %d\n",c1,vc[1].back().first,vc[1].back().second);
                vc[1].pop_back();
            }
            else
            {
                int y=1;
                while(y==c0||y==c1) y++;
                printf("%d %d %d\n",y,vc[1].back().first,vc[1].back().second);
                vc[1].pop_back();
            }
        }
        fflush(stdout);
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