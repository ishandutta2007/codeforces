#include <bits\stdc++.h>
using namespace std;

int main()
{
	unsigned long long n,m;
	vector<unsigned long long> f;
	unsigned long long i,j,l,r,mid,res;
	
	scanf("%I64d%I64d",&n,&m);
	
	for (i=1;i*i<n;i++)
	{
		if (n%i==0) f.push_back(i),f.push_back(n/i);
	}
	if (i*i==n) f.push_back(i);
	
	res=0;
	for (i=0;i<f.size();i++)
	{
		if (n*2/(1+m)/m>=f[i]) res=max(res,f[i]);
	}
	
	if (res==0) return cout<<"-1\n",0;
	
	long long sum=0;
	for (i=1;i<m;i++) sum+=i*res,printf("%I64d%c",i*res,i==m?'\n':' ');printf("%I64d%c",n-sum,i==m?'\n':' ');
	return 0;
}