#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<int> V1,V2;
char x[100010];

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='1') V2.push_back(1);
		else V1.push_back(x[i]-'0');
	}
	
	for(int i=0;i<V1.size();i++)
	{
		if(V1[i]==2) while(!V2.empty()) printf("%d",V2.back()), V2.pop_back();
		printf("%d",V1[i]);
	}
	while(!V2.empty()) printf("%d",V2.back()), V2.pop_back();
}