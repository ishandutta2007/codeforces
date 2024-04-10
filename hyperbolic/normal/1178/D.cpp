#include <stdio.h>
#include <vector>
bool isPrime(int k)
{
	for(int i=2;i*i<=k;i++) if(k%i==0) return false;
	return true;
}

std::vector<int> V[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++) V[i].push_back(i+1);
	V[a].push_back(1);
	
	int b = a/2;
	int count = a;
	
	for(int i=1;i<=b;i++)
	{
		if(isPrime(count)) break;
		V[i].push_back(i+b);
		count++;
	}
	
	printf("%d\n",count);
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++) printf("%d %d\n",i,V[i][j]);
	}
}