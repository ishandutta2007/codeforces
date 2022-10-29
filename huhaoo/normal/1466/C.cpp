/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-09-14 23:33:22
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
const int N=500010;
int n;
char a[N];
int main()
{
	fr(T,1,read())
	{
		scanf("%s",a+1); n=strlen(a+1); int ans=0;
		fr(i,2,n) if(a[i-1]==a[i]||a[i-2]==a[i])
		{
			ans++;
			for(a[i]='a';a[i]<='z';a[i]++)
			{
				int flag=0;
				fr(j,i-2,i+2) if(j!=i&&a[j]==a[i]) flag=1;
				if(!flag) break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}