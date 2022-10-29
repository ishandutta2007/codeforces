/***************************************************************
	File name: A.cpp
	Author: huhao
	Create time: Mon 15 Jun 2020 09:21:14 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=100010,mod=998244353;
i64 &Add(i64 &a,i64 b){ return a=(a+b)%mod; }
i64 f[N][8][10],ans,n,i;
#define forall fr(x,0,7) fr(y,0,7) if((x&y)==x)
void trans(int b,int a){ forall Add(f[i+1][y][a],f[i][x][b]); }
void Trans(int b,int a){ Add(f[i+1][2][a],f[i][7][b]); }
void dp()
{
	for(i=1;i<=n-1;i++)
	{
		// transform 0
		trans(0,6); Trans(0,2);
/*		Add(f[i+1][0][6],f[i][0][0]); Add(f[i+1][1][6],f[i][0][0]); Add(f[i+1][2][6],f[i][0][0]); Add(f[i+1][3][6],f[i][0][0]);
		Add(f[i+1][1][6],f[i][1][0]); Add(f[i+1][3][6],f[i][1][0]);
		Add(f[i+1][2][6],f[i][2][0]); Add(f[i+1][3][6],f[i][2][0]);
		Add(f[i+1][3][6],f[i][3][0]);*/

		// transform 1
		trans(1,7); Trans(1,3);

		// transform 2
		trans(2,1);

		// transform 3
		trans(3,0);

		// transform 4
		trans(4,6); Trans(4,2);

		// transform 5
		trans(5,4);

		// transform 6
		trans(6,7); Trans(6,3);

		// transform 7
		trans(7,5);

		// transform (i,i+1)
		fr(x,0,7) fr(y,0,7) fr(z,0,7) if((x&y)==x&&(y&z)==y) fr(op,0,7) if(op==0||op==2||op==4)
			Add(f[i+2][z][4],f[i][x][op]);
	}
}
int main()
{
	n=read();
	memset(f,0,sizeof(f)); f[1][0][2]=f[1][2][2]=1;
	dp(); Add(ans,f[n][7][0]+f[n][7][4]);
	memset(f,0,sizeof(f)); f[1][0][3]=f[1][2][3]=1;
	dp(); Add(ans,f[n][7][1]+f[n][7][6]);
	printf("%lld\n",ans);
	return 0;
}