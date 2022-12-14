#include <stdio.h>
#include <map>
long long int MAX = 1;
int x[200010];
std::map<int,int> count;
int main()
{
	for(int i=1;i<=15;i++) MAX *= 10;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) if(x[i]%b!=0) goto u;
		printf("0\n");
		continue;
		
		u:;
		for(int i=1;i<=a;i++)
		{
			if(x[i]%b!=0) count[b-(x[i]%b)]++;
		}
		
		long long int M = 0;
		for(std::map<int,int> ::iterator it = count.begin(); it!=count.end();it++)
		{
			long long int C = ((it->first)+(long long int)((it->second)-1)*b);
			M = M>C? M:C;
		}
		printf("%lld\n",M+1);
	}
}