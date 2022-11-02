#include<bits/stdc++.h>
using namespace std;
int a, b, c;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	b -= 1;
	c -= 2;
	printf("%d\n",3*min({a, b, c}) + 3);
}