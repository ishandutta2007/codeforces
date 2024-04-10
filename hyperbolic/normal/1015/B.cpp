#include <stdio.h>
#include <vector>
char x[110],y[110];
void swap(int k)
{
	char c = x[k];
	x[k] = x[k+1];
	x[k+1] = c;
}
std::vector<int> ans;
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s%s",x+1,y+1);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		{
			if(y[i]==x[j])
			{
				for(int k=j-1;k>=i;k--)
				{
					ans.push_back(k);
					swap(k);
				}
				goto u;
			}
		}
		printf("-1");
		return 0;
		u:;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}