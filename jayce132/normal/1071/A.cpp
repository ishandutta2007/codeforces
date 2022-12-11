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

set<int>A,B;

int main()
{
	int a=read(),b=read(),aa=a,bb=b,sp=0;
	if(a>b)swap(a,b),swap(aa,bb),sp=1;
	int now=0;
	for(now=1;aa>=now;aa-=now,now++)
	{
		A.insert(now);
	}
	int st=now;
	for(now;bb>=now;bb-=now,now++)
	{
		B.insert(now);
	}
	
	
	if(aa)
	{
		int t=st-aa;
		A.erase(t); A.insert(st);
		B.erase(st); B.insert(t);
		bb+=aa;
		for(now;bb>=now;bb-=now,now++)
		{
			B.insert(now);
		}
	}
	
	if(!sp)
	{
		
		printf("%d\n",A.size());
		for(int v:A)printf("%d ",v);puts("");
		printf("%d\n",B.size());
		for(int v:B)printf("%d ",v);puts("");
	}else
	{
		
		printf("%d\n",B.size());
		for(int v:B)printf("%d ",v);puts("");
		printf("%d\n",A.size());
		for(int v:A)printf("%d ",v);puts("");
	}
	return 0;
}