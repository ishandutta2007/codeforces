#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,a;
	scanf("%d%d",&n,&a);
	if(a%2==0){
		a = n+2-a;
	}
	a = (a+1)/2;
	printf("%d",a);
	return 0;
}