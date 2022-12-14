#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V;
int main()
{
	int a,b,c,d;
	int e,f;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%d:%d",&e,&f);
	
	for(int i=300;i<1440;i+=c) V.push_back({i,i+d});
	int start = 60*e+f;
	if((start-300)%a!=0) start = ((start-300)/a+1)*a + 300;
	int end = start + b;
	
	int count = 0;
	for(int i=0;i<V.size();i++)
	{
		if((V[i].second-start)*(end-V[i].first)>0) count++;
	}
	printf("%d",count);
}