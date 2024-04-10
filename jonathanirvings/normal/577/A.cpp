#include <stdio.h>
#include <iostream>
using namespace std;

int n,x;

typedef long long LL;

int main()
{
	scanf("%d %d",&n,&x);
	LL risan = 0;
	for (int i = 1; i <= n; ++i) 
	{
		if (x % i == 0 && x / i <= n) ++risan;
	}
	cout << risan << endl;
}