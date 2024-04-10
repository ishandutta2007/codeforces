#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

long long int x[200010];
long long int S[200010];
std::set< std::pair<int,int> > ans;

int bit[200010];
int check[50];
int next[200010],prev[200010],next2[200010],prev2[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int b = x[i];
		while(b)
		{
			bit[i]++;
			b/=2;
		}
	}
	
	for(int i=1;i<=a;i++) S[i] = S[i-1] + x[i];
	
	for(int j=0;j<=40;j++) check[j] = a+1;
	for(int i=a;i>=1;i--)
	{
		next[i] = check[bit[i]];
		for(int j=0;j<=bit[i];j++) check[j] = i;
	}
	for(int j=0;j<=40;j++) check[j] = a+1;
	for(int i=a;i>=1;i--)
	{
		next2[i] = check[bit[i]];
		for(int j=0;j<bit[i];j++) check[j] = i;
	}
	
	for(int j=0;j<=40;j++) check[j] = 0;
	for(int i=1;i<=a;i++)
	{
		prev[i] = check[bit[i]];
		for(int j=0;j<=bit[i];j++) check[j] = i;
	}
	for(int j=0;j<=40;j++) check[j] = 0;
	for(int i=1;i<=a;i++)
	{
		prev2[i] = check[bit[i]];
		for(int j=0;j<bit[i];j++) check[j] = i;
	}
	
	for(int i=1;i<=a;i++)
	{
		int t = next[i];
		int count = 200;
		int control = 0;
		while(t<=a&&count>=1)
		{
			count--;
			if(t==i+1)
			{
				if(control==1) control = 0,t = next2[t];
				else
				{
					if(bit[next[t]]==bit[t]) control = 1;
					else control = 0;
					t = next[t];
				}
			}
			else
			{
				if(S[t-1]-S[i]==(x[t]^x[i])) ans.insert(std::make_pair(i,t));
				if(control==1) control = 0,t = next2[t];
				else
				{
					if(bit[next[t]]==bit[t]) control = 1;
					else control = 0;
					t = next[t];
				}
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		int t = prev[i];
		int count = 200;
		int control = 0;
		while(t>=1&&count>=1)
		{
			count--;
			if(t==i-1)
			{
				if(control==1) control = 0,t = prev2[t];
				else
				{
					if(bit[prev[t]]==bit[t]) control = 1;
					else control = 0;
					t = prev[t];
				}
			}
			else
			{
				if(S[i-1]-S[t]==(x[i]^x[t])) ans.insert(std::make_pair(t,i));
				if(control==1) control = 0,t = prev2[t];
				else
				{
					if(bit[prev[t]]==bit[t]) control = 1;
					else control = 0;
					t = prev[t];
				}
			}
		}
	}
	printf("%d",ans.size());
}