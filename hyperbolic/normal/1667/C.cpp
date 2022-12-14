#include <stdio.h>
#include <vector>

int check[1000010];
std::vector< std::pair<int,int> > ans;
int main()
{
	int a;
	scanf("%d",&a);
	if(a<=2)
	{
		printf("1\n");
		printf("1 1");
		return 0;
	}
	if(a==3)
	{
		printf("2\n");
		printf("1 1\n");
		printf("1 2\n");
		return 0;
	}
	
	int ans3 = 12345678;
	std::pair<int,int> ans2 = std::make_pair(-1,-1);
	int b = a/3;
	for(int i=b;i<=b+2;i++)
	{
		for(int j=b;j<=b+2;j++)
		{
			int A = (i-1), B = a-(i+j)+1;
			if(A<=0) continue;
			if(B<=0) continue;
			int L = A>j?A:j;
			int R = B>j-1?B:j-1;
			if(L+R<ans3)
			{
				ans3 = L+R;
				ans2 = std::make_pair(i,j);
			}
		}
	}
	
	int A = ans2.first-1>ans2.second?ans2.first-1:ans2.second;
	int B = a-(ans2.first+ans2.second)+1>ans2.second-1?a-(ans2.first+ans2.second)+1:ans2.second-1;
	
	for(int i=1;i<=A;i++) ans.push_back(std::make_pair(i,ans2.second-i+1));
	if(A%2!=B%2) for(int i=1;i<=B;i++) ans.push_back(std::make_pair(a-i+1, a-(B-i+1)+1));
	else
	{
		B++;
		for(int i=2;i<=B-1;i++) ans.push_back(std::make_pair(a-i+1, a-(B-i+1)+1));
		ans.push_back(std::make_pair(a,a));
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}