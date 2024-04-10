#include <stdio.h>
#include <algorithm>
#define MIN -123456789
int x[1000010],a,b;

int check[1000010][3][3];
int func(int k, int first, int second)
{
	if(check[k][first][second]!=-1) return check[k][first][second];
	if(first+second>x[k]) return MIN;
	int t = x[k]-first-second;
	
	if(k==b) return t/3;
	int s1,s2,s3;
	s1 = func(k+1,0,first)+t/3;
	if(k==b-1) return s1;
	
	if(t>=1) s2 = func(k+1,1,first)+1+(t-1)/3;
	else s2 = MIN;
	if(t>=2) s3 = func(k+1,2,first)+2+(t-2)/3;
	else s3 = MIN;
	return check[k][first][second] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		x[c]++;
	}
	
	for(int i=1;i<=b;i++) for(int j=0;j<=2;j++) for(int k=0;k<=2;k++) check[i][j][k] = -1;
	
	printf("%d",func(1,0,0));
}