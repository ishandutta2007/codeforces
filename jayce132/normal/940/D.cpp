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

const int maxn=1e5+20;

int n,a[maxn],b[maxn],ok[maxn];

void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n)
	{
		char ch;cin>>ch;
		if(ch=='0')b[i]=0;else b[i]=1;
	}
	REP(i,5,n)
	{
		REP(j,2,4)if(b[i-j]!=b[i-1])ok[i]=0;
		ok[i]=1;
	}
}

int L=-1e9,R=1e9;

void chkmax(int &a,int b){ if(a<b)a=b;}
void chkmin(int &a,int b){ if(a>b)a=b;}

void doing()
{
	REP(i,5,n)
	{
		if(b[i]==b[i-1])
		{
			if(b[i]==0)
			{
				//if(ok[i])REP(j,0,4)chkmax(L,a[i-j]+1);
			}else
			{
				//if(ok[i])REP(j,0,4)chkmin(R,a[i-j]-1);
			}
		}else
		{
			if(b[i]==0)
			{
				if(ok[i])REP(j,0,4)chkmin(R,a[i-j]-1);
			}else
			{
				if(ok[i])REP(j,0,4)chkmax(L,a[i-j]+1);
			}
		}
	}
	printf("%d %d\n",L,R);
}

int main()
{
	//freopen("d.in","r",stdin);
	//freopen("d.out","w",stdout);
	init();
	doing();
	return 0;
}