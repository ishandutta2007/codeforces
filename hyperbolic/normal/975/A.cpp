#include <stdio.h>
#include <set>
#include <string.h>

std::set<int> S;

int check[30];
char x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		for(int j=0;j<=25;j++) check[j] = 0;
		for(int j=1;j<=b;j++) check[x[j]-'a'] = 1;
		int s = 0;
		for(int j=0;j<=25;j++)
		{
			s*=2;
			s+=check[j];
		}
		S.insert(s);
	}
	printf("%d",S.size());
}