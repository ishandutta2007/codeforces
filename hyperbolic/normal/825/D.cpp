#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<char> V;
char x[1000010],y[1000010];
long long int count1[30],count2[30];
int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	
	int c = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='?') c++;
		else count1[x[i]-'a']++;
	}
	for(int i=1;i<=b;i++) count2[y[i]-'a']++;
	
	int min = 0, max = 1000000;
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		long long int sum = 0;
		for(int i=0;i<26;i++) if(count2[i]*h>count1[i]) sum += (count2[i]*h-count1[i]);
		if(sum<=c)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	
	for(int i=0;i<26;i++) if(count2[i]*ans>count1[i]) for(long long int j=count1[i]+1;j<=count2[i]*ans;j++) V.push_back('a'+i);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='?')
		{
			if(V.empty()) printf("a");
			else
			{
				printf("%c",V.back());
				V.pop_back();
			}
		}
		else printf("%c",x[i]);
	}
}