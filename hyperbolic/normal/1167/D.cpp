#include <stdio.h>
#include <vector>

int a;
std::vector<int> V;
char x[200010];
void func(int k)
{
	if(k>a) return;
	if(x[k]=='(')
	{
		if(V.empty())
		{
			printf("0");
			V.push_back(0);
		}
		else
		{
			printf("%d",1-V.back());
			V.push_back(1-V.back());
		}
	}
	else
	{
		printf("%d",V.back());
		V.pop_back();
	}
	func(k+1);
}
int main()
{
	scanf("%d",&a);
	scanf("%s",x+1);
	func(1);
}