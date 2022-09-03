#include<cstdio>
#include<algorithm>
#include<set>

int a[100000];
std::set<long long> S;

int main()
{
	int r=0;
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(i=0;i<n;i++)if(a[i]%m!=0||S.find(a[i]/m)==S.end())
	{
		r++;
		S.insert(a[i]);
	}
	printf("%d",r);
}