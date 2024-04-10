#include <stdio.h>
#include <vector>

char x[1010],y[1010];
int count[3];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count[0] = count[1] = 0;
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) count[x[i]-'0']++;
		for(int i=1;i<=count[0];i++) y[i] = '0';
		for(int i=count[0]+1;i<=a;i++) y[i] = '1';
		
		std::vector<int> temp;
		for(int i=1;i<=a;i++) if(x[i]!=y[i]) temp.push_back(i);
		if(temp.size()==0) printf("0\n");
		else
		{
			printf("1\n%d ",temp.size());
			for(int i=0;i<temp.size();i++) printf("%d ",temp[i]);
			printf("\n");
		}
	}
}