#include <stdio.h>
#include <string.h>
#include <vector>

char x[100010];
int y[100010];
std::vector<int> V;
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) y[i] = x[i]-'a';
	V.push_back(26);
	int p = 1;
	while(p<=a)
	{
		int min = 26;
		for(int i=p;i<=a;i++) min = min<y[i]?min:y[i];
		while(min>=V.back())
		{
			printf("%c",V.back()+'a');
			V.pop_back();
		}
		
		int last;
		for(int i=a;i>=p;i--)
		{
			if(y[i]==min)
			{
				last = i;
				break;
			}
		}
		for(int i=p;i<=last;i++)
		{
			if(y[i]==min) printf("%c",y[i]+'a');
			else V.push_back(y[i]);
		}
		p = last+1;
	}
	while(V.size()>=2) printf("%c",V.back()+'a'),V.pop_back();
}