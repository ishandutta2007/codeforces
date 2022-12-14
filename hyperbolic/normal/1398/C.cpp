#include <stdio.h>
#include <map>

std::map<long long int,int> check;
char x[100010];
long long int s[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		check.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) s[i] = s[i-1] + (x[i]-'0');
		for(int i=0;i<=a;i++) s[i]-=i;
		for(int i=0;i<=a;i++) check[s[i]]++;
		
		long long int ans = 0;
		for(std::map<long long int,int> ::iterator it = check.begin();it!=check.end();it++)
		{
			long long int k = it->second;
			ans += k*(k-1)/2;
		}
		printf("%lld\n",ans);
	}
}