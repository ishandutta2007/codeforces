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

const int maxn=1e5+20;

int n,a[maxn],id[maxn];
int got[maxn];

int main()
{
	n=read();
	REP(i,1,n)a[i]=read(),id[a[i]]=i;
	got[n]=0;
	DREP(i,n-1,1)
	{
		int x=id[i];
		for(int st=x%i;st<=n;st+=i)
		{
			if(a[st]>i && !got[st]){got[x]=1;break;}
		}
	}
	REP(i,1,n)printf("%c",got[i]?'A':'B');
	return 0;
}