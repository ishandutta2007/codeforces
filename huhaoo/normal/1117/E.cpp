/****************************************************************
	File name: 1117E.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2/18/2019, 11:33:17 PM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
#define N 10010
char s[N],I[N],O[N];
int a[N],b[N],c[N],n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	fr(i,0,n-1)
		O[i]=i/26/26+'a';
	printf("? %s\n",O);
	fflush(stdout);
	scanf("%s",I);
	fr(i,0,n-1)
		a[i]=I[i]-'a';
	fr(i,0,n-1)
		O[i]=(i/26)%26+'a';
	printf("? %s\n",O);
	fflush(stdout);
	scanf("%s",I);
	fr(i,0,n-1)
		b[i]=I[i]-'a';
	fr(i,0,n-1)
		O[i]=i%26+'a';
	printf("? %s\n",O);
	fflush(stdout);
	scanf("%s",I);
	fr(i,0,n-1)
		c[i]=I[i]-'a';
	fr(i,0,n-1)
	{
		int j=a[i]*26*26+b[i]*26+c[i];
//		printf("%d %d %d %d %d %c\n",i,a[i],b[i],c[i],j,s[j]);
		O[j]=s[i];
	}
	printf("! %s\n",O);
	return 0;
}