#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
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

int a[520][520];

const int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
	int n=read(),m=read();
	REP(i,1,n)REP(j,1,m)
	{
		char ch;
		cin>>ch;
		if(ch=='.')a[i][j]=0;
		else if(ch=='S')a[i][j]=1;
		else a[i][j]=2;
	}

	REP(i,1,n)
	{
		REP(j,1,m)
		{
			if(a[i][j]==2)
			REP(l,0,3)
			{
				int x=i+d[l][0],y=j+d[l][1];
				if(a[x][y]==1)
				{
					puts("No");
					exit(0);
				}
			}
		}
	}
	puts("Yes");
	REP(i,1,n)
	{
		REP(j,1,m)
		{
			if(a[i][j]==0)a[i][j]=3;
			if(a[i][j]==1)printf("S");
			else if(a[i][j]==2)printf("W");
			else printf("D");
		}
		puts("");
	}
	return 0;
}