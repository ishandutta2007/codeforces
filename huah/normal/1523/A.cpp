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
const int N=5e5+5,mod=998244353;
int n,m;
char s[N];
int main()
{
    int t;sc(t);
    while(t--)
    {
        sc(n,m);
        sc(s+1);
        int pre=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='1')
        {
            if(!pre)
            {
                for(int j=i-1;j>=max(1,i-m);j--)
                    s[j]='1';
            }
            else
            {
                for(int l=pre+1,r=i-1,j=m;j>0&&l<r;l++,r--,j--)
                    s[l]=s[r]='1';
            }
            pre=i;
        }
        if(pre)
            for(int j=pre+1;j<=min(n,pre+m);j++) s[j]='1';
        printf("%s\n",s+1);
    }
}