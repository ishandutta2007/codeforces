#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

std::vector<char> V1,V2;
char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		V1.clear();
		V2.clear();
		int b;
		scanf("%s",x+1);
		b = strlen(x+1);
		for(int j=1;j<=b;j++)
		{
			if((x[j]-'a')%2==0) V2.push_back(x[j]);
			else V1.push_back(x[j]);
		}
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		if(V2.empty()) for(int j=0;j<V1.size();j++) printf("%c",V1[j]);
		else if(V1.empty()) for(int j=0;j<V2.size();j++) printf("%c",V2[j]);
		else
		{
			if(V1.back()+1 == V2.front() || V1.back()-1 == V2.front())
			{
				if(V2.back()+1 == V1.front() || V2.back()-1 == V1.front()) printf("No answer");
				else
				{
					for(int j=0;j<V2.size();j++) printf("%c",V2[j]);
					for(int j=0;j<V1.size();j++) printf("%c",V1[j]);
				}
			}
			else
			{
				for(int j=0;j<V1.size();j++) printf("%c",V1[j]);
				for(int j=0;j<V2.size();j++) printf("%c",V2[j]);
			}
		}
		printf("\n");
	}
}