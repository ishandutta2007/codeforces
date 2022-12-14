#include <stdio.h>
#include <vector>

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
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b%2==1) V1.push_back(b);
			else V2.push_back(b);
		}
		
		int control = 0;
		for(int i=1;i<V1.size();i++) if(V1[i-1]>V1[i]) control = 1;
		for(int i=1;i<V2.size();i++) if(V2[i-1]>V2[i]) control = 1;
		
		printf("%s\n",control==1?"No":"Yes");
	}
}