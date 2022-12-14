#include <stdio.h>
#include <vector>

std::vector<char> V[5010];
int count[5010][30];
char x[5010];
std::vector<int> index;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		V[i].push_back(0);
		for(int j=1;j<=b;j++) V[i].push_back(x[j]);
		V[i].push_back(0);
	}
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) count[i][V[i][j]-'a']++;
	
	for(int i=1;i<a;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(count[i][j]!=count[i+1][j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	int control = 0;
	for(int i=2;i<=a;i++)
	{
		std::vector<int> temp;
		for(int j=1;j<=b;j++) if(V[1][j]!=V[i][j]) temp.push_back(j);
		if(temp.size()>0)
		{
			if(2<=temp.size()&&temp.size()<=4)
			{
				control = i;
				index = temp;
				break;
			}
			else
			{
				printf("-1");
				return 0;
			}
		}
	}
	if(control==0)
	{
		printf("%c%c",V[1][2],V[1][1]);
		for(int i=3;i<=b;i++) printf("%c",V[1][i]);
		return 0;
	}
	
	if(index.size()==2)
	{
		for(int i1=0;i1<index.size();i1++)
		{
			for(int j1=1;j1<=b;j1++)
			{
				int s = index[i1];
				int t = j1;
				if(s==t) continue;
				
				char c = V[1][s];
				V[1][s] = V[1][t];
				V[1][t] = c;
				
				for(int i=2;i<=a;i++)
				{
					int C = 0;
					for(int j=1;j<=b;j++) if(V[1][j]!=V[i][j]) C++;
					
					if(C==0)
					{
						for(int j=0;j<26;j++)
						{
							if(count[1][j]>=2) goto u3;
						}
						goto u4;
					}
					else if(C==2);
					else goto u4;
					u3:;
				}
				
				for(int j=1;j<=b;j++) printf("%c",V[1][j]);
				return 0;
				
				u4:;
				c = V[1][s];
				V[1][s] = V[1][t];
				V[1][t] = c;
			}
		}
		printf("-1");
		return 0;
	}
	
	for(int i1=0;i1<index.size();i1++)
	{
		for(int j1=i1+1;j1<index.size();j1++)
		{
			int s = index[i1];
			int t = index[j1];
			char c = V[1][s];
			V[1][s] = V[1][t];
			V[1][t] = c;
			
			for(int i=2;i<=a;i++)
			{
				int C = 0;
				for(int j=1;j<=b;j++) if(V[1][j]!=V[i][j]) C++;
				
				if(C==0)
				{
					for(int j=0;j<26;j++)
					{
						if(count[1][j]>=2) goto u1;
					}
					goto u2;
				}
				else if(C==2);
				else goto u2;
				u1:;
			}
			
			for(int j=1;j<=b;j++) printf("%c",V[1][j]);
			return 0;
			
			u2:;
			c = V[1][s];
			V[1][s] = V[1][t];
			V[1][t] = c;
		}
	}
	
	printf("-1");
}