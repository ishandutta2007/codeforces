#include <bits/stdc++.h>
using namespace std;

const int a[4]={4,9,25,49};

bool is_prime(int x)
{
	for (int i=2;i<x;i++)
		if (x%i==0)
			return false;
	return true;
}

int main()
{
	char op[50];
	int cnt=0;
	for (int i=0;i<4;i++)
	{
		printf("%d\n",a[i]);
		fflush(stdout);
		scanf("%s",op);
		if (op[0]=='y')
		{
			printf("composite\n");
			fflush(stdout);
			return 0;
		}
	}
	for (int i=2;i<=50;i++)
		if (is_prime(i))
		{
			printf("%d\n",i);
			fflush(stdout);
			scanf("%s",op);
			if (op[0]=='y') cnt++;
		}
	if (cnt<=1) printf("prime\n");
	else printf("composite\n");
	fflush(stdout);
	return 0;
}