#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i;
int main()
{
	cin>>n;
	printf("2\n");
	for(i=2;i<=n;i++)cout<<(i+2LL)*i*i+1<<endl;
	return 0;
}