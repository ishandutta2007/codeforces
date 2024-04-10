#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define fr(i,a,b) for(int i=a,_end_=b;i<=_end_;i++)
#define fd(i,a,b) for(int i=a,_end_=b;i>=_end_;i--)
using namespace std;
int read(){
	int s=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		k=c=='-'?-1:1;
		c=getchar();
	}		
	while(c>='0'&&c<='9'){
		s=(s<<1)+(s<<3)+(c^48);
		c=getchar();
	}
	return s*k;
}
#define N 510
int n,m;
char s[N][N];
int main()
{
	n=read();
	m=read();
	fr(i,1,n)scanf("%s",s[i]+1);
	fr(i,1,n)fr(j,1,m)if(s[i][j]=='.')s[i][j]='D';
	fr(i,1,n)fr(j,1,m)if(s[i][j]=='W')
	{
		if(s[i+1][j]=='S')
		{
			printf("No\n");
			return 0;
		}
		
		if(s[i-1][j]=='S')
		{
			printf("No\n");
			return 0;
		}
		
		if(s[i][j+1]=='S')
		{
			printf("No\n");
			return 0;
		}
		
		if(s[i][j-1]=='S')
		{
			printf("No\n");
			return 0;
		}
		
	}
	printf("Yes\n");
	fr(i,1,n)
		printf("%s\n",s[i]+1);
	return 0;
}