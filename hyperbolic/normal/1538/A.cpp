#include <stdio.h>
#include <vector>
#include <algorithm>

int x[110];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int min = x[1], max = x[1];
		for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		for(int i=1;i<=a;i++) if(x[i]==min) V.push_back(i);
		for(int i=1;i<=a;i++) if(x[i]==max) V.push_back(i);
		std::sort(V.begin(),V.end());
		int s1 = V[1];
		int s2 = (a-V[0]+1);
		int s3 = V[0]+(a-V[1]+1);
		printf("%d\n",s1<s2?s3<s1?s3:s1:s3<s2?s3:s2);
	}
}