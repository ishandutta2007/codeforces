/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-07 17:43:07
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
const int w=26,N=1<<w|10;
int b[N],n,a[400010],ans;
int main()
{
	n=read();
	fr(i,1,n) a[i]=read();
	fr(i,0,26)
	{
		fr(j,1,n)
		{
			int A=((1<<(i+1))-1)&a[j];
			int l=std::max((1<<i)-A,0),r=(1<<(i+1))-1-A;
			r=std::min(r,(1<<w)-1);
			if(l<=r)
			{
				if(l) for(int k=l;k;k-=k&(-k)) ans^=b[k]<<i;
				for(int k=r+1;k;k-=k&(-k)) ans^=b[k]<<i;
			}
			l=std::max((3<<i)-A,0),r=(4<<i)-1-A;
			r=std::min(r,(1<<w)-1);
			if(l<=r)
			{
				if(l) for(int k=l;k;k-=k&(-k)) ans^=b[k]<<i;
				for(int k=r+1;k;k-=k&(-k)) ans^=b[k]<<i;
			}
			for(int k=A+1;k<=(1<<w);k+=k&(-k)) b[k]^=1;
//			printf("%d %d %d  %d\n",l,r,A,ans);
		}
		fr(j,1,n)
		{
			int A=((1<<(i+1))-1)&a[j];
			for(int k=A+1;k<=(1<<w);k+=k&(-k)) b[k]^=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}