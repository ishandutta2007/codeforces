#include <stdio.h>
#include <vector>
#include <algorithm>

int x[110];
std::vector<int> V;
int main()
{
	int a;
	scanf("%d",&a);
	
	int s1 = 0 ,s2 = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=b;j++) scanf("%d",&x[j]);
		if(b%2==0)
		{
			for(int j=1;j<=b/2;j++) s1 += x[j];
			for(int j=b/2+1;j<=b;j++) s2 += x[j];
		}
		else
		{
			int h = (b+1)/2;
			for(int j=1;j<=h-1;j++) s1 += x[j];
			for(int j=h+1;j<=b;j++) s2 += x[j];
			V.push_back(x[h]);
		}
	}
	if(V.size()>0)
	{
		std::sort(V.begin(),V.end());
		for(int t = (int)V.size()-1;t>=0;t-=2) s1 += V[t];
		for(int t = (int)V.size()-2;t>=0;t-=2) s2 += V[t];
	}
	
	printf("%d %d",s1,s2);
}