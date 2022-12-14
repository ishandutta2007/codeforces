#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> V,V2;
char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int s = 1, t = a;
	while(1)
	{
		while(x[s]==')') s++;
		while(x[t]=='(') t--;
		if(s>t) break;
		V.push_back(s), V2.push_back(t);
		s++,t--;
	}
	if(V.size()==0)
	{
		printf("0");
		return 0;
	}
	printf("1\n%d\n",2*V.size());
	for(int i=0;i<V.size();i++) printf("%d ",V[i]);
	for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
}