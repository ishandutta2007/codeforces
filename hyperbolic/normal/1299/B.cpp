#include <stdio.h>
#include <vector>
int func(std::pair<int,int> A1,std::pair<int,int> A2,std::pair<int,int> B1,std::pair<int,int> B2)
{
	long long int x1 = A1.first-A2.first;
	long long int y1 = A1.second-A2.second;
	long long int x2 = B1.first-B2.first;
	long long int y2 = B1.second-B2.second;
	if(x1*y2==x2*y1&& (x1*x1+y1*y1)==(x2*x2+y2*y2)) return 1;
	else return 0;
}

std::pair<int,int> x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].first,&x[i].second);
	x[a+1].first = x[1].first, x[a+1].second = x[1].second;
	
	if(a%2==1) printf("NO");
	else
	{
		int b = a/2;
		for(int i=1;i<=b;i++)
		{
			int s = func(x[i],x[i+1],x[b+i],x[b+i+1]);
			if(s==0)
			{
				printf("NO");
				return 0;
			}
		}
		printf("YES");
	}
}