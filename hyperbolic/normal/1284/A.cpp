#include <stdio.h>
#include <vector>
#include <string.h>
std::vector<char> V1[30],V2[30];
char x[20];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%s",x+1);
		int c = strlen(x+1);
		for(int j=1;j<=c;j++) V1[i].push_back(x[j]);
	}
	for(int i=0;i<b;i++)
	{
		scanf("%s",x+1);
		int c = strlen(x+1);
		for(int j=1;j<=c;j++) V2[i].push_back(x[j]);
	}
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		d--;
		for(int j=0;j<V1[d%a].size();j++) printf("%c",V1[d%a][j]);
		for(int j=0;j<V2[d%b].size();j++) printf("%c",V2[d%b][j]);
		printf("\n");
	}
}