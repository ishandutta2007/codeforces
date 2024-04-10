#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x,y;
int main()
{
	scanf("%d%d:%d",&n,&x,&y);
	if(y>59)y%=10;
	if(n==24&&x>23)x%=10;
	if(n==12&&x>12)x%=10;
	if(n==12&&!x)x=10;
	printf("%.2d:%.2d\n",x,y);
	return 0;
}