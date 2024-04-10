/**************************************************************
	File name: 1205C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/18 10:32:22
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=110;
int n;
int a[N][N];
int dx[20]={-2	,-1	,0	,0	,1	,2};
int dy[20]={0	,-1	,2	,-2	,1	,0};
void draw(int x,int y)
{
	fr(i,0,5)
	{
		int X=x+dx[i],Y=y+dy[i];
		if(!(X<1||Y<1||X>n||Y>n||a[X][Y]!=-1))
		{
			printf("? %d %d %d %d\n",min(x,X),min(y,Y),max(x,X),max(y,Y));
			fflush(stdout);
			a[X][Y]=a[x][y]^(read()^1);
			draw(X,Y);
		}
	}
}
int main()
{
	n=read();
	fr(i,1,n)
		fr(j,1,n)
			a[i][j]=-1;
	a[1][1]=a[1][2]=1;
	a[n][n]=0;
	draw(1,1);
	draw(1,2);
	int op;
	fr(i,1,n-2)
		if(a[i][i]!=a[i+2][i+2])
		{
			if(a[i][i]==a[i+1][i+1])
			{
				if(a[i][i+1]==a[i+1][i+2])
				{
					printf("? %d %d %d %d\n",i,i,i+1,i+2);
					fflush(stdout);
					op=(read()?a[i][i]:a[i][i]^1)?a[i][i+1]:a[i][i+1]^1;
				}
				else
				{
					printf("? %d %d %d %d\n",i,i+1,i+2,i+2);
					fflush(stdout);
					op=(read()?a[i+2][i+2]:a[i+2][i+2]^1)?a[i][i+1]:a[i][i+1]^1;
				}
			}
			else
			{
				if(a[i][i+1]!=a[i+1][i+2])
				{
					printf("? %d %d %d %d\n",i,i,i+1,i+2);
					fflush(stdout);
					op=(read()?a[i+1][i+1]:a[i+1][i+1]^1)?a[i][i+1]:a[i][i+1]^1;
				}
				else
				{
					printf("? %d %d %d %d\n",i,i+1,i+2,i+2);
					fflush(stdout);
					op=(read()?a[i+2][i+2]:a[i+2][i+2]^1)?a[i][i+1]:a[i][i+1]^1;
				}
			}
			break;
		}
	fr(i,1,n)
		fr(j,1,n)
			if((i+j)%2==1)
				a[i][j]=(a[i][j]==op);
	printf("!\n");
	fr(i,1,n)
	{
		fr(j,1,n)
			printf("%d",a[i][j]);
		putchar(10);
	}
	return 0;
}
/*
100
111
100

110
000
110
*/