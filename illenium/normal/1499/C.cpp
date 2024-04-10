#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,c[maxn],ans,t1,t2;
multiset <ll> s1,s2;
multiset <ll>::iterator it;

inline void jud()
{
	if(s1.size()==0||s2.size()==0) return;
	it=s1.begin(); ll tmp=*it,p=t1-tmp;
	p+=(n-s1.size()+1)*tmp;
	
	it=s2.begin(); tmp=*it; p+=t2-tmp;
	p+=(n-s2.size()+1)*tmp;
	
	ans=min(ans,p);
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); rep(i,1,n) c[i]=read(); t1=0; t2=0; ans=inf;
		rep(i,1,n)
		{
			if(i%2==1)
			{
				t1+=c[i]; s1.ins(c[i]); jud();
			}
			else
			{
				t2+=c[i]; s2.ins(c[i]); jud();
			}
		}
		s1.clear(); s2.clear();
		printf("%lld\n",ans);
	}
	return 0;
}