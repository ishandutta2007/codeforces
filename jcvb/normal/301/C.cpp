#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;


int main()
{
	for (int i=0;i<=9;i++)printf("??%d>>%d??\n",i,i);
	printf("??>>?\n");
	for (int i=0;i<=8;i++)printf("%d?<>%d\n",i,i+1);
	printf("9?>>?0\n");
	printf("?0<>10\n");
	printf(">>??\n");
	return 0;
}