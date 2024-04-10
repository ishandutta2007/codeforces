#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",(2*n-1)/m+1+(5*n-1)/m+1+(8*n-1)/m+1);
	return 0;
}