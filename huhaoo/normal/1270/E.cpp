/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-12-29 22:40:03
****************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=1010;
int n,x[N],y[N],col[N],cnt[N];
int main()
{
	n=read();
	fr(i,1,n){ x[i]=read()+1000000; y[i]=read()+1000000; }
	fr(i,0,30) fr(j,1,2)
	{
		cnt[0]=cnt[1]=0;
		fr(k,1,n)
		{
			if(j==1) cnt[col[k]=((x[k]>>i)+(y[k]>>i))%2]++;
			else cnt[col[k]=(x[k]>>i)%2]++;
		}
		if(cnt[0]&&cnt[1])
		{
			printf("%d\n",cnt[0]);
			fr(k,1,n) if(!col[k]) printf("%d ",k);
			putchar(10);
//			fprintf(stderr,"%d %d\n",i,j);
			return 0;
		}
	}
	return 0;
}