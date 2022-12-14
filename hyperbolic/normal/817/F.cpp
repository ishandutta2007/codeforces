#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define SIZE 800

int type[600010],sum[600010],x[600010];

void update(int s)
{
	if(type[s]==1)
	{
		for(int i=s*SIZE;i<(s+1)*SIZE;i++) x[i] = 1;
		sum[s] = SIZE;
	}
	else if(type[s]==2)
	{
		for(int i=s*SIZE;i<(s+1)*SIZE;i++) x[i] = 0;
		sum[s] = 0;
	}
	else if(type[s]==3)
	{
		for(int i=s*SIZE;i<(s+1)*SIZE;i++) x[i] = 1-x[i];
		sum[s] = SIZE-sum[s];
	}
	type[s] = 0;
}

std::vector<long long int> index;
std::map<long long int,int> hash;
struct str{
	int first;
	long long int second;
	long long int third;
}query[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		long long int c,d;
		scanf("%d%lld%lld",&b,&c,&d);
		query[i]={b,c,d};
		index.push_back(c);
		if(c>1) index.push_back(c-1);
		index.push_back(c+1);
		index.push_back(d);
		index.push_back(d+1);
		if(d>1) index.push_back(d-1);
	}
	index.push_back(1);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	
	for(int k=1;k<=a;k++)
	{
		int b = query[k].first;
		int c = hash[query[k].second];
		int d = hash[query[k].third];
		
		int s = c/SIZE, t = d/SIZE;
		update(s);
		update(t);
		
		if(d-c<=SIZE)
		{
			if(b==1)
			{
				for(int i=c;i<=d;i++)
				{
					if(x[i]==0)
					{
						x[i] = 1;
						sum[i/SIZE]++;
					}
				}
			}
			else if(b==2)
			{
				for(int i=c;i<=d;i++)
				{
					if(x[i]==1)
					{
						x[i] = 0;
						sum[i/SIZE]--;
					}
				}
			}
			else
			{
				for(int i=c;i<=d;i++)
				{
					if(x[i]==1)
					{
						x[i] = 0;
						sum[i/SIZE]--;
					}
					else
					{
						x[i] = 1;
						sum[i/SIZE]++;
					}
				}
			}
		}
		else
		{
			if(b==1)
			{
				for(int i=c;i<(s+1)*SIZE;i++)
				{
					if(x[i]==0)
					{
						x[i] = 1;
						sum[i/SIZE]++;
					}
				}
				for(int i=t*SIZE;i<=d;i++)
				{
					if(x[i]==0)
					{
						x[i] = 1;
						sum[i/SIZE]++;
					}
				}
				for(int i=s+1;i<=t-1;i++) type[i] = 1;
			}
			else if(b==2)
			{
				for(int i=c;i<(s+1)*SIZE;i++)
				{
					if(x[i]==1)
					{
						x[i] = 0;
						sum[i/SIZE]--;
					}
				}
				for(int i=t*SIZE;i<=d;i++)
				{
					if(x[i]==1)
					{
						x[i] = 0;
						sum[i/SIZE]--;
					}
				}
				for(int i=s+1;i<=t-1;i++) type[i] = 2;
			}
			else
			{
				for(int i=c;i<(s+1)*SIZE;i++)
				{
					if(x[i]==0)
					{
						x[i] = 1;
						sum[i/SIZE]++;
					}
					else
					{
						x[i] = 0;
						sum[i/SIZE]--;
					}
				}
				for(int i=t*SIZE;i<=d;i++)
				{
					if(x[i]==0)
					{
						x[i] = 1;
						sum[i/SIZE]++;
					}
					else
					{
						x[i] = 0;
						sum[i/SIZE]--;
					}
				}
				for(int i=s+1;i<=t-1;i++)
				{
					if(type[i]==0) type[i] = 3;
					else if(type[i]==1) type[i] = 2;
					else if(type[i]==2) type[i] = 1;
					else if(type[i]==3) type[i] = 0;
				}
			}
		}
		
		for(int i=0;i<=index.size()/SIZE;i++)
		{
			if(type[i]==0 && sum[i]!=SIZE)
			{
				for(int j=i*SIZE;j<(i+1)*SIZE;j++)
				{
					if(x[j]==0)
					{
						printf("%lld\n",index[j]);
						goto u;
					}
				}
			}
			else if(type[i]==2)
			{
				printf("%lld\n",index[i*SIZE]);
				goto u;
			}
			else if(type[i]==3&&sum[i]!=0)
			{
				for(int j=i*SIZE;j<(i+1)*SIZE;j++)
				{
					if(x[j]==1)
					{
						printf("%lld\n",index[j]);
						goto u;
					}
				}
			}
		}
		
		u:;
	}
}