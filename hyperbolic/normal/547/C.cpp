#include <stdio.h>
#include <vector>
#include <set>

int check[500010];
int num(int k)
{
	if(check[k]) return check[k];
	int ans = 0;
	for(int i=1;i*i<=k;i++)
	{
		if(i*i==k) ans++;
		else if(k%i==0) ans+=2;
	}
	return check[k] = ans;
}

int count[500010];
std::vector<int> temp;
long long int func(int k, int t)
{
	if(t==temp.size())
	{
		return count[k];
	}
	long long int s1 = func(k,t+1);
	long long int s2 = func(k*temp[t],t+1);
	return s1-s2;
}
void func2(int k ,int t, int val)
{
	if(t==temp.size())
	{
		count[k]+=val;
		return;
	}
	func2(k,t+1,val);
	func2(k*temp[t],t+1,val);
}

int x[200010];
int check2[500010];
std::vector<int> V[200010],prime;
std::set<int> S;

int main()
{
	for(int i=2;i<=500000;i++)
	{
		if(check2[i]==0)
		{
			for(int j=i;j<=500000;j+=i) check2[j] = 1;
			prime.push_back(i);
		}
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int t = x[i];
		for(int j=0;j<prime.size()&&prime[j]*prime[j]<=x[i];j++)
		{
			if(x[i]%prime[j]==0) V[i].push_back(prime[j]);
			while(t%prime[j]==0) t/=prime[j];
		}
		if(t>1) V[i].push_back(t);
	}
	long long int sum = 0;
	for(int i=1;i<=b;i++)
	{
		int e;
		scanf("%d",&e);
		int c = x[e];
		temp.clear();
		int d = c;
		for(int j=0;j<prime.size()&&prime[j]*prime[j]<=c;j++)
		{
			if(c%prime[j]==0) temp.push_back(prime[j]);
			while(d%prime[j]==0) d/=prime[j];
		}
		if(d>1) temp.push_back(d);
		if(S.find(e)!=S.end())
		{
			func2(1,0,-1);
			sum -= func(1,0);
			printf("%lld\n",sum);
			S.erase(e);
		}
		else
		{
			sum += func(1,0);
			printf("%lld\n",sum);
			func2(1,0,1);
			S.insert(e);
		}
	}
}