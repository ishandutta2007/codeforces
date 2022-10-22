#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,c;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d %d %d\n",c+b+a,c+b,c);
	}
	return 0;
}