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
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,k;
vector<int>vc[N];
int main()
{
  	// freopen("1.in","r",stdin);
    int t=1;
    sc(t);
    while(t--)
    {
		sc(n,k);
		rep(i,1,n) 
		{
			int x;sc(x);
			if(vc[x].size()<k) vc[x].push_back(i);
		}
		vector<int>ans(n+1);
		rep(i,1,n) ans[i]=0;
		int cur=1,tot=0;
		int res=0;
		rep(i,1,n) res+=int(vc[i].size());
		res=res/k*k;
		rep(i,1,n)
		{
			while(!vc[i].empty())
			{
				if(tot<res) ans[vc[i].back()]=cur++,tot++;
				if(cur>k) cur-=k;
				vc[i].pop_back();
			}
		}
		rep(i,1,n) printf(i==n?"%d\n":"%d ",ans[i]);
	}
}
/*
aaabaa
*/