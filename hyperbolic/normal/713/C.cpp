#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX (long long int)1e16

int abs(int k)
{
	return k>0?k:-k;
}

std::vector<int> index;
long long int check[3010][3010];
int x[3010],a;
long long int func(int s, int t)
{
	if(t>=index.size()) return MAX;
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s1 = func(s,t+1);
	long long int s2 = abs(x[s]-index[t]) + func(s+1,t);
	return check[s][t] = (s1<s2?s1:s2);
}


int main()
{
	scanf("%d",&a);
	if(a==1)
	{
		printf("0");
		return 0;
	}
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) x[i] -= i;
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	std::sort(index.begin(),index.end());
	
	for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) check[i][j] = -1;
	
	printf("%lld",func(1,0));
}