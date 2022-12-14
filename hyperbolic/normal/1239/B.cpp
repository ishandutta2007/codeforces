#include <stdio.h>
#include <deque>

std::deque<int> D[600010];
char x[600010];
int y[600010],next[600010];

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int count1 = 0, count2 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='(') count1++;
		else count2++;
	}
	if(count1!=count2)
	{
		printf("0\n");
		printf("1 1");
		return 0;
	}
	for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
	
	next[2*a+1] = 2*a+1;
	int p = 2*a+1;
	for(int i=2*a;i>=1;i--)
	{
		next[i] = p;
		if(x[i]=='(') p = i;
	}
	
	for(int i=1;i<=2*a;i++)
	{
		if(x[i]=='(') y[i] = 1;
		else y[i] = -1;
	}
	for(int i=1;i<=2*a;i++) y[i] += y[i-1];
	for(int i=1;i<=a;i++) D[y[i]+a].push_back(i);
	
	int ans = 0,ind1 = -1, ind2 = -1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==')')
		{
			if(D[y[i-1]-3+a].size()==0)
			{
				int t = next[D[y[i-1]-1+a].back()];
				//printf("%d %d!!\n",i,t);
				if(t<=i+a-1)
				{
					int s1 = D[y[i-1]-2+a].size();
					int s2 = 0;
					int min = 0, max = D[y[i-1]+a].size()-1;
					while(min<=max)
					{
						int h = (min+max)/2;
						if(D[y[i-1]+a][h]>=t)
						{
							s2 = D[y[i-1]+a].size() - h;
							max = h-1;
						}
						else min = h+1;
					}
					//printf("%d %d??\n",s1,s2);
					
					if(ans<s1+s2)
					{
						ans = s1+s2;
						ind1 = i, ind2 = t;
					}
				}
			}
		}
		else
		{
			if(D[y[i-1]-1+a].size()==0)
			{
				int s = D[y[i-1]+a].size();
				if(ans<s)
				{
					ans = s;
					ind1 = i, ind2 = i;
				}
			}
		}
		D[y[i]+a].pop_front();
		D[y[a+i]+a].push_back(a+i);
	}
	
	if(ind1>a) ind1-=a;
	if(ind2>a) ind2-=a;
	printf("%d\n",ans);
	printf("%d %d",ind1,ind2);
}