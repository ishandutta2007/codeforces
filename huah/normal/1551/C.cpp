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
string s[N];
int sol(char c)
{
	vector<int>vc;
	rep(i,1,n)
	{
		int sum=0;
		for(char x:s[i])
			if(x==c) sum++;
			else sum--;
		vc.push_back(sum);
	}
	sort(vc.begin(),vc.end());
	int ans=0;
	if(vc.back()>0)
	{
		ans++;
		ll sum=vc.back();
		vc.pop_back();
		while(!vc.empty()&&sum+vc.back()>0) ans++,sum+=vc.back(),vc.pop_back();
	}
	return ans;
}
int main()
{
  	// freopen("1.in","r",stdin);
    int t=1;
    sc(t);
    while(t--)
    {
		cin>>n;
		rep(i,1,n) cin>>s[i];
		int ans=0;
		rep(i,0,4) ans=max(ans,sol(i+'a'));
		out(ans);
	}
}
/*
aaabaa
*/