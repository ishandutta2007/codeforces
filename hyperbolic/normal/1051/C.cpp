#include <stdio.h>
#include <vector>

int count[110],color[110];
std::vector<int> V1,V2,V3;
char x[110];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) count[x[i]]++;
	for(int i=1;i<=100;i++) if(count[i]==1) V1.push_back(i);
	for(int i=1;i<=100;i++) if(count[i]==2) V2.push_back(i);
	for(int i=1;i<=100;i++) if(count[i]>=3) V3.push_back(i);
	if(V1.size()%2==0)
	{
		for(int i=0;i<V1.size();i+=2) color[V1[i]] = 1;
		for(int i=1;i<V1.size();i+=2) color[V1[i]] = 2;
		for(int i=0;i<V2.size();i++) color[V2[i]] = 1;
		for(int i=0;i<V3.size();i++) color[V3[i]] = 1;
		printf("YES\n");
		for(int i=1;i<=a;i++) printf("%c",color[x[i]]+'A'-1);
	}
	else
	{
		if(V3.size()==0)
		{
			printf("NO");
			return 0;
		}
		
		for(int i=0;i<V1.size();i+=2) color[V1[i]] = 1;
		for(int i=1;i<V1.size();i+=2) color[V1[i]] = 2;
		for(int i=0;i<V2.size();i++) color[V2[i]] = 1;
		for(int i=1;i<V3.size();i++) color[V3[i]] = 1;
		printf("YES\n");
		int control = 0;
		for(int i=1;i<=a;i++)
		{
			if(color[x[i]]==0)
			{
				if(control==0)
				{
					printf("B");
					control++;
				}
				else printf("A");
			}
			else printf("%c",color[x[i]]+'A'-1);
		}
	}
}