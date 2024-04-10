#include <bits/stdc++.h>
using namespace std;

int n,b,g,ans,i,j;

int main()
{
	scanf("%d%d%d",&b,&g,&n);
	
	b=min(b,n);g=min(g,n);
	
	cout<<n+1-(n*2-b-g)<<endl;
	
	return 0;
}