#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2,x;
int main()
{
	scanf("%d:%d%d:%d",&a1,&b1,&a2,&b2);
	x=(a1+a2)*30+(b1+b2)/2;
	printf("%.2d:%.2d\n",x/60,x%60);
	return 0;
}