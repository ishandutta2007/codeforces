#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[110];
char x[110];
int a,b;
long long int power[110];
int ans[110];

void func(int k, int L, int R, long long int C)
{
	if(k>b) return;
	int h = L-1;
	for(int i=L;i<=R;i++) if(V[i][k-1]==0) h = i;
	
	long long int C1 = power[b-k] - (h-L+1);
	long long int C2 = power[b-k] - (R-h);
	
	if(C<C1)
	{
		ans[k] = 0;
		func(k+1,L,h,C);
	}
	else
	{
		ans[k] = 1;
		func(k+1,h+1,R,C-C1);
	}
}

int main()
{
	power[0] = 1;
	for(int i=1;i<=60;i++) power[i] = power[i-1]*2;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			V[i].clear();
			for(int j=1;j<=b;j++) V[i].push_back(x[j]-'0');
		}
		
		std::sort(V+1,V+a+1);
		
		long long int C = power[b];
		C -= a;
		
		func(1,1,a,(C-1)/2);
		for(int i=1;i<=b;i++) printf("%d",ans[i]);
		printf("\n");
	}
}