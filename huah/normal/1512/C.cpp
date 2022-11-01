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
int n,a,b;
char s[N];
int main()
{
  	// freopen("1.in","r",stdin);
    int t=1;
    sc(t);
    while(t--)
    {
		sc(a,b);sc(s+1);
		n=strlen(s+1);
		if(a+b!=n){out(-1);continue;}
		vector<pair<int,int>>pr;
		int center=-1;
		bool flag=true;
		for(int i=1,j=n;i<=j;i++,j--)
			if(s[i]!=s[j])
			{
				if(!(s[i]=='?'||s[j]=='?'))
				{
					flag=false;break;
				}
				if(s[i]=='?') s[i]=s[j];
				else s[j]=s[i];
				if(s[i]=='0')
					a-=1+(i!=j);
				else b-=1+(i!=j);
			}
			else if(s[i]=='?')
			{
				if(i!=j) pr.push_back({i,j});
				else center=i;
			}
			else
			{
				if(s[i]=='0')
					a-=1+(i!=j);
				else b-=1+(i!=j);
			}
		
		if(!flag||b<0||a<0) out(-1);
		else
		{
			if(center!=-1)
			{
				if(a&1) s[center]='0',a--;
				else s[center]='1',b--;
			}
			if((a&1)||(b&1))
			{
				out(-1);
			}
			else
			{
				while(pr.size())
				{
					if(a>=2) s[pr.back().first]=s[pr.back().second]='0',a-=2;
					else s[pr.back().first]=s[pr.back().second]='1',b-=2;
					pr.pop_back();
				}
				cout<<s+1<<'\n';
			}
		}
	}
}