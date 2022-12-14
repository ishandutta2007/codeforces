#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

std::vector<int> V[100010];
int check[100010];
int func(int k, int num, int p)
{
	if(k==V[num].size()) return check[p];
	
	int S = 0;
	S += func(k+1,num,p);
	S -= func(k+1,num,p*V[num][k]);
	return S;
}

void insert(int k, int num, int val, int p)
{
	if(k==V[num].size()) check[p] += val;
	else
	{
		insert(k+1,num,val,p);
		insert(k+1,num,val,p*V[num][k]);
	}
}

int x[100010];
std::vector<int> V2[100010];
std::stack<int> St;
int main()
{
	for(int i=2;i<=100000;i++) if(V[i].size()==0) for(int j=i;j<=100000;j+=i) V[j].push_back(i);
	
	long long int ans = 0;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=a;i>=1;i--)
	{
		if(x[i]==x[i+1])
		{
			ans = ans>x[i]?ans:x[i];
			continue;
		}
		
		for(int j=1;j*j<=x[i];j++)
		{
			if(x[i]%j==0)
			{
				V2[j].push_back(x[i]/j);
				if(j*j!=x[i]) V2[x[i]/j].push_back(j);
			}
		}
	}
	
	for(int g=1;g<=100000;g++)
	{
		while(!St.empty())
		{
			int k = St.top();
			insert(0,k,-1,1);
			St.pop();
		}
		
		long long int S = 0;
		for(int i=0;i<V2[g].size();i++)
		{
			int control = 0;
			int m = func(0,V2[g][i],1);
			if(m>0)
			{
				control = 1;
				int count = 0;
				int s = V2[g][i];
				while(!St.empty())
				{
					int k = St.top();
					insert(0,k,-1,1);
					St.pop();
					if(gcd(k,s)==1)
					{
						S = S>(long long int)k*s?S:(long long int)k*s;
						count++;
						if(count==m) break;
					}
				}
			}
			if(control==0)
			{
				insert(0,V2[g][i],1,1);
				St.push(V2[g][i]);
			}
		}
		ans = ans>S*g?ans:S*g;
	}
	printf("%lld",ans);
}