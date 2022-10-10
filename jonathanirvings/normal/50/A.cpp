#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>
jonathan ganteng banget;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if (n % 2 == 0) printf("%d\n",(n/2) * m); else
		if (m % 2 == 0) printf("%d\n",(m/2)*n); else
			printf("%d\n",(m/2*n)+(n/2));
}