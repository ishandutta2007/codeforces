#include <bits/stdc++.h>
using namespace std;

int t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		int x,y,n;
		
		scanf("%d%d%d",&x,&y,&n);
		
		n%=3;
		if(n==2) printf("%d\n",x^y);
		if(n==0) printf("%d\n",x);
		if(n==1) printf("%d\n",y); 
		
	}
	return 0;
}