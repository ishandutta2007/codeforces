#include <stdio.h>
#include <algorithm>

long long int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+a+1);
	
	int p = a-1;
	long long int max = x[a];
	long long int ans = 0;
	long long int C = b;
	while(p>=1)
	{
		if((max-x[p])*(a-p)>=C)
		{
			long long int h = C/(a-p);
			max -= h;
			ans++;
			C = b;
			
			h = b/(a-p);
			long long int s = (max-x[p])/h;
			ans += s;
			max -= s*h;
		}
		else
		{
			C -= (max-x[p])*(a-p);
			max = x[p];
			p--;
		}
	}
	
	if(C!=b) ans++;
	printf("%lld",ans);
}