#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e6+20;

int n,k;
int a[maxn];

inline void init()
{
	n=read();k=read();
	REP(i,1,n)a[i]=read();
}

int st[maxn],top;
int L[maxn],R[maxn];

const int mod=1e9+7;

int ans;

inline void doing()
{
	st[top=0]=0;
	REP(i,1,n)
	{
		while(top && a[st[top]]<=a[i])top--;
		L[i]=st[top]+1;
		st[++top]=i;
	}
	st[top=0]=n+1;
	DREP(i,n,1)
	{
		while(top && a[st[top]]<a[i])top--;
		R[i]=st[top]-1;
		st[++top]=i;
	}

	REP(i,1,n)
	{
		int l=L[i],r=R[i],x=i,res=0;

		int t1=(r-x)/(k-1),t2=(x-l)/(k-1),t3=(r-l)/(k-1);
		res=(res+(ll)x*t1)%mod; res=(res+ (ll)r*(t3-t1) )%mod;
		res=(res-(ll)(t1+1+t3)*(t3-t1)/2%mod*(k-1)%mod+mod)%mod;

		res=(res+(ll)(t2)*(t2+1)/2%mod*(k-1))%mod; res=(res-(ll)x*(t2)%mod+mod)%mod;
		res=(res-(ll)(t3-t2)*l%mod+mod)%mod;
		res=(res+t3)%mod;
		ans=(ans+(ll)res*a[i])%mod;
	}
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("maxinum.in","r",stdin);
	freopen("maxinum.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}