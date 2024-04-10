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
int n,q;
char s[N];
int sum[N][3];
int main()
{
  	// freopen("1.in","r",stdin);
    int t=1;
    // sc(t);
    while(t--)
    {
		sc(n,q);
		sc(s+1);
		rep(i,1,n)
		{
			memset(sum[i],0,sizeof(sum[i]));
			if(i>=3)
				rep(j,0,2) sum[i][j]=sum[i-3][j];
			sum[i][s[i]-'a']++;
		}
		while(q--)
		{
			int l,r;sc(l,r);
			vector<int>a(3);
			rep(i,0,2) a[i]=i;
			int ans=0;
			function<int(int,int,int)>query=[&](int l,int r,int id)
			{
				if(r<l) return 0;
				int ans=0;
				if(r>=0) ans+=sum[r][id];
				int x=r-(r-l)/3*3;
				if(x>=l) x-=3;
				if(x>=0) ans-=sum[x][id];
				return ans;
			};
			while(true)
			{
				ans=max(ans,query(l,r,a[0])+query(l,r-1,a[1])+query(l,r-2,a[2]));
				if(!next_permutation(a.begin(),a.end())) break;
			}
			out(r-l+1-ans);
		}
	}
}
/*
10 1
cbcccaacaa
3 6
*/