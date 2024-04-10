/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-03 22:40:12
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
char s[N];
int p[N],c,n;
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	for(int l=1,r=n;;)
	{
		while(l<=n&&s[l]!='(') l++;
		while(r>=1&&s[r]!=')') r--;
		if(l>r) break;
		c+=2; p[l]=p[r]=1; l++; r--;
	}
	if(c)
	{
		printf("1\n%d\n",c);
		fr(i,1,n) if(p[i]) printf("%d%c",i,--c?' ':'\n');
	}
	else printf("0\n");
	return 0;
}