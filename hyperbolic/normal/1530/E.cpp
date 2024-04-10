#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> V;
int count[30];
char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<26;i++) count[i] = 0;
		V.clear();
		
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) count[x[i]-'a']++;
		
		int C = 0;
		for(int i=0;i<26;i++)
		{
			if(count[i]==1)
			{
				printf("%c",'a'+i);
				count[i]--;
				for(int j=0;j<26;j++)
				{
					while(count[j]>=1)
					{
						printf("%c",'a'+j);
						count[j]--;
					}
				}
				printf("\n");
				goto u;
			}
			if(count[i]>0) C++;
		}
		
		if(C==1)
		{
			for(int i=1;i<=a;i++) printf("%c",x[i]);
			printf("\n");
		}
		else
		{
			int p1 = -1;
			for(int i=0;i<26;i++)
			{
				if(count[i]>0)
				{
					p1 = i;
					break;
				}
			}
			count[p1]--;
			
			int sum = 0;
			for(int i=p1+1;i<26;i++) sum += count[i];
			if(count[p1]-1>=sum+1)
			{
				int p2 = -1;
				for(int i=p1+1;i<26;i++)
				{
					if(count[i]>0)
					{
						p2 = i;
						break;
					}
				}
				count[p2]--;
				
				int p3 = -1;
				for(int i=p2+1;i<26;i++)
				{
					if(count[i]>0)
					{
						p3 = i;
						break;
					}
				}
				
				printf("%c%c",'a'+p1,'a'+p2);
				
				if(p3!=-1)
				{
					while(count[p1]>=1)
					{
						printf("%c",'a'+p1);
						count[p1]--;
					}
					printf("%c",'a'+p3);
					count[p3]--;
					for(int i=p2;i<26;i++)
					{
						while(count[i]>=1)
						{
							printf("%c",'a'+i);
							count[i]--;
						}
					}
					printf("\n");
				}
				else
				{
					while(count[p2]>=1)
					{
						printf("%c",'a'+p2);
						count[p2]--;
					}
					while(count[p1]>=1)
					{
						printf("%c",'a'+p1);
						count[p1]--;
					}
					printf("\n");
				}
			}
			else
			{
				printf("%c",'a'+p1);
				for(int i=p1+1;i<26;i++)
				{
					while(count[i]>=1)
					{
						V.push_back(i);
						count[i]--;
					}
				}
				for(int i=0;i<count[p1];i++)
				{
					printf("%c",'a'+p1);
					if(i<V.size()) printf("%c",'a'+V[i]);
				}
				for(int i=count[p1];i<V.size();i++) printf("%c",'a'+V[i]);
				printf("\n");
				
			}
		}
		
		u:;
	}
}