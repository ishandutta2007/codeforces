#include <stdio.h>
#include <algorithm>
long long int MAX = 3;
long long int func(long long int a, long long int b, long long int c)
{
	return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
}

int size[10];
int x[5][100010];
int y[10];
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&size[1],&size[2],&size[3]);
		for(int i=1;i<=3;i++) for(int j=1;j<=size[i];j++) scanf("%d",&x[i][j]);
		for(int i=1;i<=3;i++) std::sort(x[i]+1,x[i]+size[i]+1);
		
		long long int ans = MAX;
		y[1] = 1, y[2] = 2, y[3] = 3;
		do{
			int p2 = 1, p3=1;
			for(int i=1;i<=size[y[1]];i++)
			{
				while(p2<=size[y[2]] && x[y[2]][p2]<x[y[1]][i]) p2++;
				if(p2>size[y[2]]) break;
				while(p3<=size[y[3]] && x[y[3]][p3]<(x[y[1]][i]+x[y[2]][p2])/2) p3++;
				
				long long int S;
				if(p3-1>=1) S = func(x[y[1]][i],x[y[2]][p2],x[y[3]][p3-1]), ans = ans<S?ans:S;
				if(p3<=size[y[3]]) S = func(x[y[1]][i],x[y[2]][p2],x[y[3]][p3]), ans = ans<S?ans:S;
			}
		}while(std::next_permutation(y+1,y+4));
		
		printf("%lld\n",ans);
	}
}