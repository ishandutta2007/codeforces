#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	V.push_back(1);
	for(int i=1;i<b;i++)
	{
		V.push_back(i);
		for(int j=i+2;j<=b;j++)
		{
			V.push_back(j);
			V.push_back(i);
		}
		V.push_back(i+1);
	}
	for(int i=b;i>=2;i--) V.push_back(i);
	
	int c = V.size();
	for(int i=0;i<a;i++) printf("%c",'a'+V[i%c]-1);
}