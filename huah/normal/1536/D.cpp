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
const int N=5e5+5;
int n,a[N];
set<int>s;
int main()
{
    int t;sc(t);
    while(t--)
    {
        sc(n);
        bool flag=true;
        rep(i,1,n) sc(a[i]);
        s.clear();
        s.insert(a[1]);
        rep(i,2,n)
        {
            s.insert(a[i]);
            if(a[i]==a[i-1]) continue;
            if(a[i]<a[i-1])
            {
                auto it=s.lower_bound(a[i-1]);
                it--;
                if((*it)!=a[i])
                {
                    flag=false;break;
                }
            }
            else
            {
                auto it=s.upper_bound(a[i-1]);
                if((*it)!=a[i])
                {
                    flag=false;break;
                }
            }
        }
        printf(flag?"YES\n":"NO\n");
    }
}