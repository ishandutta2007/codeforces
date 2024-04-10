#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
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
int readi()
{
	int t=1,r=0,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	r=(r<<3)+(r<<1)+(c^48);
	return r*t;
}
#define N 1010
int n;
int p[10],x[10]={0,0,1,1},y[10]={0,1,0,1},cc[10][N][N],c[N][N],ans=1000010;
int main()
{
	n=read();
	fr(i,1,4)
		fr(j,1,n)
			fr(k,1,n)
				cc[i][j][k]=readi();
	fr(i,1,4)p[i]=i-1;
	do
	{
		fr(i,1,4)
			fr(j,1,n)
				fr(k,1,n)
					c[x[p[i]]*n+j][y[p[i]]*n+k]=cc[i][j][k];
//		fr(i,1,n*2)
//			fr(j,1,n*2)
//				printf("%d%c",c[i][j],j==_end_?'\n':' ');
		int th=0;
		fr(i,1,n*2)
			fr(j,1,n*2)
			{
				if(c[i][j]!=((i^j)&1))th++;
//				printf("%d %d %d %d\n",i,j,c[i][j],(i^j)&1);
			}
		ans=min(ans,th);
	}while(next_permutation(p+1,p+5));
	printf("%d\n",ans);
	return 0;
}