#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
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
const int N=505;
int n,d[N];
bool query(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    char s[20];scanf("%s",s+1);
    return s[1]=='Y';
}
vector<pair<int,int>>vec[N];
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n);
    rep(i,1,n) sc(d[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        if(d[i]>d[j])
        vec[d[i]-d[j]].push_back({i,j});
        else vec[d[j]-d[i]].push_back({j,i});
    nep(i,n-1,0)
    if(vec[i].size())
    {
        sort(vec[i].begin(),vec[i].end());
        reverse(vec[i].begin(),vec[i].end());
        for(pair<int,int>x:vec[i])
        {
            if(query(x.first,x.second))
            {
                printf("! %d %d\n",x.first,x.second);
                return 0;
            }
        }
    }
    printf("! 0 0\n");
}