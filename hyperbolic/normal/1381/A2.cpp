#include <stdio.h>
#include <vector>

char x[100010],y[100010];
std::vector<int> V1,V2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		for(int i=2;i<=a;i++) if(x[i]!=x[i-1]) V1.push_back(i-1);
		for(int i=2;i<=a;i++) if(y[i]!=y[i-1]) V2.push_back(i-1);
		if(x[a]!=y[a]) V1.push_back(a);
		
		printf("%d ",V1.size()+V2.size());
		for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
		for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
		printf("\n");
	}
}