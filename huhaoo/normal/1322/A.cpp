/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-07 17:29:27
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
const int N=1000010;
char c[N];
int s,ans;
int main()
{
	read(); scanf("%s",c+1);
	fr(i,1,strlen(c+1))
	{
		s+=c[i]=='('?1:-1;
		ans+=s<0&&c[i]==')';
//		printf("%d\n",s);
	}
	printf("%d\n",s==0?ans*2:-1);
	return 0;
}