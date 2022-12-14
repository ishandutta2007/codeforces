#include <stdio.h>
#include <vector>

int check[2000010];
std::vector<int> V1,V2,V3;
int main()
{
	for(int i=2;i<=2000000;i++) if(check[i]==0) for(int j=2*i;j<=2000000;j+=i) check[j] = 1;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b==1) V1.push_back(1);
		else if(b%2==0) V2.push_back(b);
		else V3.push_back(b);
	}
	
	int max = 0;
	int ans1 = -1, ans2 = -1;
	if(V2.size()>0) max = 1, ans1 = V2[0];
	else if(V3.size()>0) max = 1, ans1 = V3[0];
	
	for(int i=0;i<V2.size();i++)
	{
		for(int j=0;j<V3.size();j++)
		{
			if(check[V2[i]+V3[j]]==0)
			{
				max = 2;
				ans1 = V2[i], ans2 = V3[j];
			}
		}
	}
	
	for(int i=0;i<V2.size();i++)
	{
		if(check[V2[i]+1]==0 && V1.size()+1>=max)
		{
			printf("%d\n",V1.size()+1);
			for(int j=0;j<V1.size();j++) printf("%d ",V1[j]);
			printf("%d",V2[i]);
			return 0;
		}
	}
	
	if(V1.size()>=max)
	{
		printf("%d\n",V1.size());
		for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
		return 0;
	}
	
	printf("%d\n",max);
	if(max==2) printf("%d %d",ans1,ans2);
	else printf("%d",ans1);
}