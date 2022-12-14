#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> St;
char x[100010],y[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		if(St.empty()) St.push_back(i);
		else
		{
			int k = St.back();
			if(x[k]=='1'&&x[i]=='0')
			{
				y[k] = '1';
				y[i] = '0';
				St.pop_back();
			}
			else St.push_back(i);
		}
	}
	for(int i=1;i<=a;i++) if(y[i]==0) y[i]='0';
	for(int i=1;i<=a;i++) printf("%c",y[i]);
}