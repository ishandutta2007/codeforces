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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1<<12;


int n,p3[20];
int a[maxn],s[1000020];
char str[maxn];
int m,k;

inline void init()
{
	n=read(); m=read();k=read();
	p3[0]=1; REP(i,1,n)p3[i]=p3[i-1]*3;
	REP(i,1,m)a[read()]++;
	REP(i,0,(1<<n)-1)
	{
		int t=0;
		REP(j,0,n-1)if(i>>j&1)t+=p3[j];
		s[t]+=a[i];
	}
}

ll ans;

inline void doing()
{
	REP(i,0,p3[n]-1)
	{
		REP(j,0,n-1)if(i/p3[j]%3==2)
		{
			int a=i-p3[j],b=a-p3[j];
			s[i]=s[a]+s[b];
			break;
		}
	}
	REP(i,1,k)
	{
		ans=0;
		scanf("%s",str); reverse(str,str+n);
		int sum=0,flg=0;
		for(int S=0;S<(1<<n);S++)
		{
			sum=flg=0;
			for(int j=0,l=strlen(str);j<l;j++)
			{
				char ne=S>>j&1,now=0;
				if(str[j]=='A')now=ne?0:2;
				else if(str[j]=='O')now=ne?(flg=1,0):0;
				else if(str[j]=='X')now=ne;
				else if(str[j]=='a')now=ne?1:(flg=1,0);
				else if(str[j]=='o')now=ne?2:1;
				else if(str[j]=='x')now=ne^1;
				sum+=p3[j]*now;
				if(flg)break;
			}
			if(!flg)ans+=(ll)a[S]*s[sum];
		}
		printf("%lld\n",ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}