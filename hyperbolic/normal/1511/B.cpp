#include <stdio.h>

int power(int a, int b)
{
	int ans = 1;
	for(int i=1;i<=b;i++) ans*=a;
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--,b--,c--;
		if(a>=b) printf("%d %d\n",power(10,a)+power(10,c),power(10,b));
		else printf("%d %d\n",power(10,a),power(10,b)+power(10,c));
	}
}