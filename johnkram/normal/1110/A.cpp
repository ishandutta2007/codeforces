#include<bits/stdc++.h>
using namespace std;
int n,m,i,ans;
int main()
{
	scanf("%d%d",&m,&n);
	m&=1;
	while(n--)
	{
		scanf("%d",&i);
		if(n)ans^=(i&1)&&m;
		else ans^=i&1;
	}
	if(ans)puts("odd");
	else puts("even");
	return 0;
}