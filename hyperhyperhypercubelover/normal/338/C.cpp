#include<cstdio>
#include<algorithm>
#include<map>

std::map<std::pair<long long,long long>,long long> M;
long long a[10];
long long v[10];
long long w[10];
long long n;

long long dfs(long long x)
{
	long long j;
	long long i,k,l,r;
    if(x==n)
	{
		r=0;
		for(i=0;i<n;i++)
		{
			r++;
			if(M.find(std::pair<long long,long long>(a[i],v[i]))!=M.end())r+=M[std::pair<long long,long long>(a[i],v[i])];
			else
			{
				j=a[i];
				l=0;
				for(k=2;j/k/k;k++)while(j%k==0)
				{
					l++;
					j/=k;
					r++;
				}
				if(j>1&&(l||v[i]))
				{
					l++;
					r++;
				}
                M[std::pair<long long,long long>(a[i],v[i])]=l;
			}
		}
		j=0;
		for(i=0;i<n;i++)if(!w[i])j++;
		return r+(j>1);
	}
	r=2e9;
	for(i=0;i<x;i++)if(a[i]%a[x]==0&&(a[i]/a[x]>1||v[i]))
	{
		v[i]++;
		w[x]=1;
		a[i]/=a[x];
		j=dfs(x+1);
		if(j<r)r=j;
		v[i]--;
		w[x]=0;
        a[i]*=a[x];
	}
	j=dfs(x+1);
	if(j<r)r=j;
	return r;
}

int main()
{
	long long i,j,k;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)scanf("%I64d",&a[i]);
	std::sort(a,a+n);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		k=a[i];
		a[i]=a[j];
		a[j]=k;
	}
	printf("%I64d",dfs(0));
}