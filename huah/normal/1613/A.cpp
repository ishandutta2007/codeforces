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
int n;
int len(int x)
{
	int ans=0;
	while(x) x/=10,ans++;
	return ans;
}
int main()
{
  	// freopen("1.in","r",stdin);
    int t=1;
	sc(t);
	while(t--)
	{
		int x1,p1,x2,p2;
		sc(x1,p1);sc(x2,p2);
		int l1=len(x1),l2=len(x2);
		if(l1+p1!=l2+p2)
			printf(l1+p1>l2+p2?">\n":"<\n");
		else
		{
			while(l1<l2) x1*=10,l1++;
			while(l2<l1) x2*=10,l2++;
			if(x1==x2) printf("=\n");
			else printf(x1>x2?">\n":"<\n");
		}
	}
}