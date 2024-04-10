#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int n,m,i,j;
char c[5];
bool b;
int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)for(j=0;j<5;j++)
	{
		scanf("%s",c);
		if(c[0]=='C'||c[0]=='M'||c[0]=='Y')b=1;
	}
	if(b)puts("#Color");
	else puts("#Black&White");
	return 0;
}