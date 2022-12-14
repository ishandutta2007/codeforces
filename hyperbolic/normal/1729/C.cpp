#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

char x[200010];
std::vector< std::pair<char,int> > V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		int control = 0;
		if(x[1]>x[a])
		{
			control = 1;
			char t = x[1];
			x[1] = x[a];
			x[a] = t;
		}
		
		V.clear();
		for(int i=2;i<a;i++)
		{
			if(x[1]<=x[i]&&x[i]<=x[a]) V.push_back(std::make_pair(x[i],i));
		}
		std::sort(V.begin(),V.end());
		if(control) std::reverse(V.begin(),V.end());
		printf("%d %d\n",x[a]-x[1],V.size()+2);
		printf("1 ");
		for(int i=0;i<V.size();i++) printf("%d ",V[i].second);
		printf("%d\n",a);
	}
}