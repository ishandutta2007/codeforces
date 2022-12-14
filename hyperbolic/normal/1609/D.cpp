#include <stdio.h>

int next[1010],size[1010];
int check[1010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++) next[i] = i,size[i] = 1;
	check[1] = a;
	int C = 1;
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(find(c)!=find(d))
		{
			check[size[find(c)]]--;
			check[size[find(d)]]--;
			size[find(d)] += size[find(c)];
			next[find(c)] = find(d);
			check[size[find(d)]]++;
		}
		else C++;
		
		int ans = 0;
		int s = 0;
		for(int i=a;i>=1;i--)
		{
			if(s+check[i]>C)
			{
				ans += (C-s)*i;
				break;
			}
			else ans += check[i]*i, s += check[i];
		}
		printf("%d\n",ans-1);
	}
}