#include <stdio.h>
#include <algorithm>

int x[5],p[5];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&x[1],&x[2],&x[3],&x[4]);
		p[1] = 1, p[2] = 2, p[3] = 3, p[4] = 4;
		int ans = 0;
		do{
			int s = x[p[1]]<x[p[2]]?x[p[1]]:x[p[2]];
			int t = x[p[3]]<x[p[4]]?x[p[3]]:x[p[4]];
			ans = ans>s*t?ans:s*t;
		}while(std::next_permutation(p+1,p+5));
		printf("%d\n",ans);
	}
}