#include <stdio.h>
#include <vector>
#include <algorithm>

int next[100010],count[100010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int x[100010];
std::vector<long long int> V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) next[i] = i;
	
	for(int i=1;i<=a;i++)
	{
		int s = find(i);
		int t = find(x[i]);
		next[s] = t;
	}
	for(int i=1;i<=a;i++) count[find(i)]++;
	for(int i=1;i<=a;i++) if(count[i]>0) V.push_back(count[i]);
	std::sort(V.begin(),V.end());
	std::reverse(V.begin(),V.end());
	if(V.size()==1) printf("%lld",V[0]*V[0]);
	else
	{
		long long int sum = (V[0]+V[1])*(V[0]+V[1]);
		for(int i=2;i<V.size();i++) sum += V[i]*V[i];
		printf("%lld",sum);
	}
}