#include<bits/stdc++.h>
using namespace std;
int n,x,y,i;
int main()
{
	scanf("%d",&n);
	puts("YES");
	while(n--)
	{
		scanf("%d%d%*d%*d",&x,&y);
		printf("%d\n",(((x&1)<<1)|(y&1))+1);
	}
	return 0;
}