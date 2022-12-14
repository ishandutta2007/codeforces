#include <stdio.h>
#include <vector>

std::vector<int> V[60];
char x[60][60];
int a;
bool func(int s)
{
	if(V[s].size()==0) return true;
	for(int i=1;i<=a;i++)
	{
		if(V[i].size()!=V[s].size())
		{
			for(int j=0;j<V[s].size();j++) if(x[i][V[s][j]]=='#') return false;
		}
		else
		{
			if(V[i][0]==V[s][0])
			{
				for(int j=0;j<V[s].size();j++) if(V[i][j]!=V[s][j]) return false;
			}
			else
			{
				for(int j=0;j<V[s].size();j++) if(x[i][V[s][j]]=='#') return false;
			}
		}
	}
	return true;
}
int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='#') V[i].push_back(j);
	for(int i=1;i<=a;i++)
	{
		if(!func(i))
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}