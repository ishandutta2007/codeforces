#include <stdio.h>
#include <string.h>
#include <vector>
char x[200010];
std::vector<int> V[30];
int func(int k, int s, int t)
{
	if(V[k].size()==0) return 0;
	
	int min = 0, max = V[k].size()-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[k][h]>=s)
		{
			if(V[k][h]<=t) return 1;
			max = h-1;
		}
		else min = h+1;
	}
	return 0;
}

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) V[x[i]-'a'+1].push_back(i);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(x[c]!=x[d]) printf("Yes\n");
		else if(d-c+1==1) printf("Yes\n");
		else
		{
			int count = 0;
			for(int j=1;j<=26;j++) if(func(j,c,d)==1) count++;
			if(count>=3) printf("Yes\n");
			else printf("No\n");
		}
	}
}