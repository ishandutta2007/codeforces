#pragma GCC optimize(2)
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
const int N=1005,mod=998244353;
#define inf 0x3f3f3f3f
int n;
char s[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);sc(s+1);
        vector<int>v[2];
        rep(i,1,n) v[s[i]-'0'].push_back(i);
        reverse(v[1].begin(),v[1].end());
        vector<int>ans;
        while(v[0].size())
        {
            int u=v[0].back();v[0].pop_back();
            if(v[1].size()&&v[1].back()<u)
            {
                ans.push_back(u);
                ans.push_back(v[1].back());
                v[1].pop_back();
            }
            else break;
        }
        if(int(ans.size()))
        {
            out(1);
            printf("%d",int(ans.size()));
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++) printf(" %d",ans[i]);
            putchar('\n');
        }
        else out(0);
    }
}