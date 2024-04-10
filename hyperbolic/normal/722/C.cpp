#include <stdio.h>
#include <vector>
int x[100010],y[100010],next[100010];
long long int check[100010];
std::vector<long long int> V;
int find(int k)
{
	if(next[k]==0) return 0;
	if(k==next[k]) return k;
	return next[k] = find(next[k]);
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	long long int ans = 0;
	for(int i=a;i>=1;i--)
	{
		V.push_back(ans);
		check[y[i]] = x[y[i]];
		next[y[i]] =y[i];
		int k = find(y[i]-1);
		if(k>0) next[k] = y[i], check[y[i]] += check[k];
		k = find(y[i]+1);
		if(k>0) next[k] = y[i], check[y[i]] += check[k];
		ans = ans>check[y[i]]?ans:check[y[i]];
	}
	for(int i=V.size()-1;i>=0;i--) printf("%lld\n",V[i]);
}