#include <stdio.h>
#include <map>
#include <algorithm>
// key : bitState value : Grundy
std::map<long long int, int> check[100];
int func(int s, long long int t)
{
	int x[70]={} , k = 1;
	if(s==0) return 0;
	if(check[s].find(t)!=check[s].end()) return check[s][t];
	for(int i=1;i<=s;i++)
	{
		if((t&(1<<(i-1)))==0) continue;
		x[k++] = func(s-i,t-(1<<(i-1)));
	}
	k--;
	std::sort(x+1,x+k+1);
	
	int S = 0;
	for(int i=1;i<=k;i++)
	{
		if(x[i]<S) continue;
		if(x[i]==S) S++;
		if(x[i]>S)
		{
			return check[s][t] = S;	
		}
	}
	return check[s][t] = S;
}
int main()
{
	int a,b;
	int s = 0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		long long int k = 1;
		for(int i=1;i<=b;i++) k*=2;
		s^=func(b,k-1);
	}
	if(s==0) printf("YES");
	else printf("NO");
}