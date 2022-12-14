#include <stdio.h>
#include <vector>
#include <algorithm>

int sign[1010];
long long int size[1010];
std::pair<long long int,int> x[1010];
std::vector<int> left1,right1,left2,right2;
std::vector<int> ans;

long long int getQuery(int a, int b, int c, int d)
{
	printf("%d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	
	long long int e;
	scanf("%lld",&e);
	return e;
}

int main()
{
	int a;
	scanf("%d",&a);
	
	for(int i=3;i<=a;i++) sign[i] = getQuery(2,1,2,i);
	for(int i=3;i<=a;i++) size[i] = getQuery(1,1,2,i);
	for(int i=1;i<=a;i++) x[i] = std::make_pair(sign[i]*size[i],i);
	std::sort(x+1,x+a+1);
	
	int root1 = -1, root2 = -1;
	for(int i=a;i>=1;i--)
	{
		if(x[i].first==0) break;
		
		if(root1==-1) root1 = x[i].second;
		else
		{
			int t = getQuery(2,2,x[i].second,root1);
			if(t==1) right1.push_back(x[i].second);
			else left1.push_back(x[i].second);
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(x[i].first==0) break;
		
		if(root2==-1) root2 = x[i].second;
		else
		{
			int t = getQuery(2,2,x[i].second,root2);
			if(t==1) left2.push_back(x[i].second);
			else right2.push_back(x[i].second);
		}
	}
	
	ans.push_back(1);
	if(!left2.empty()) for(int i=left2.size()-1;i>=0;i--) ans.push_back(left2[i]);
	if(root2!=-1) ans.push_back(root2);
	if(!right2.empty()) for(int i=0;i<right2.size();i++) ans.push_back(right2[i]);
	ans.push_back(2);
	if(!right1.empty()) for(int i=right1.size()-1;i>=0;i--) ans.push_back(right1[i]);
	if(root1!=-1) ans.push_back(root1);
	if(!left1.empty()) for(int i=0;i<left1.size();i++) ans.push_back(left1[i]);
	
	printf("0 ");
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
}