#include <stdio.h>
#include <vector>
int abs(int k)
{
	return k>0?k:-k;
}

std::vector<int> V1,V2;
int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int count = 0;
		int L,R;
		for(int i=1;i<=a;i++) count += x[i];
		for(int i=1;i<=a;i++) if(x[i]==1) R = i;
		for(int i=a;i>=1;i--) if(x[i]==1) L = i;
		printf("%d\n",(R-L+1)-count);
	}
}