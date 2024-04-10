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
const int N=1e3+5,mod=998244353;
int n,a[N];
vector<int>v;
void print()
{
    for(int i=0;i<v.size();i++)
        printf(i==v.size()-1?"%d\n":"%d.",v[i]);
}
int main()
{
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) sc(a[i]);
        v.clear();
        v.push_back(1);
        print();
        for(int i=2;i<=n;i++)
        {
            if(a[i]==1) v.push_back(a[i]);
            else
            {
                while(v.back()+1!=a[i]) v.pop_back();
                v.pop_back();
                v.push_back(a[i]);
            }
            print();
        }
    }
}