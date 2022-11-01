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
int n,k,q,a[N];
int main()
{
  	// freopen("1.in","r",stdin);
    int t;sc(t);
	while(t--)
	{
		string s;cin>>s;
		int z=0;
		for(char c:s) z+=c=='a';
		if(z==int(s.size())) printf("NO\n");
		else
		{
			string ans1,ans2;
			bool flag=true;
			for(int i=0,j=s.size()-1;i<=j;)
			{
				if((s[i]!='a'||s[j]!='a')&&flag)
				{
					if(s[i]!='a') ans1+=s[i++],ans2+='a';
					else ans2+=s[j--],ans1+='a';
					flag=false;
				}
				else
				{
					if(i!=j) ans1+=s[i++],ans2+=s[j--];
					else ans1+=s[i++];
				}
			}
			printf("YES\n");
			reverse(ans2.begin(),ans2.end());
			cout<<ans1+ans2<<'\n';
		}
	}
}