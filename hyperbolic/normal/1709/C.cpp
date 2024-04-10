#include <stdio.h>
#include <vector>
#include <string.h>

char x[200010];
std::vector<int> V;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		int count1 = 0, count2 = 0, count3 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='(') count1++;
			if(x[i]==')') count2++;
			if(x[i]=='?') count3++;
		}
		int s = ((count2-count1)+count3)/2;
		int t = count3-s;
		if(s==0||t==0)
		{
			printf("YES\n");
			continue;
		}
		
		V.clear();
		for(int i=1;i<=a;i++) if(x[i]=='?') V.push_back(i);
		for(int i=0;i<s;i++) x[V[i]] = '(';
		for(int i=s;i<V.size();i++) x[V[i]] = ')';
		x[V[s-1]] = ')';
		x[V[s]] = '(';
		
		int C = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='(') C++;
			else C--;
			if(C<0)
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}