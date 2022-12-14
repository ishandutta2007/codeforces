#include <stdio.h>
#include <vector>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int check[35010];
std::vector<int> prime;
int main()
{
	for(int i=2;i<=35000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=35000;j+=i) check[j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		int s1 = 0 ,s2 = 0;
		int t = a;
		for(int i=0;i<prime.size();i++) while(t%prime[i]==0) s1++, t/=prime[i];
		if(t>1) s1++;
		t = b;
		for(int i=0;i<prime.size();i++) while(t%prime[i]==0) s1++, t/=prime[i];
		if(t>1) s1++;
		int g = gcd(a,b);
		
		if(a==b) s2 = 2;
		else if(a==g) s2 = 1;
		else if(b==g) s2 = 1;
		else s2 = 2;
		
		if(s2<=c && c<=s1) printf("YES\n");
		else printf("NO\n");
	}
}