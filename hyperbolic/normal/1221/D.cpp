#include <stdio.h>
#include <vector>
#include <algorithm>

long long int check[300010][4];
int x[300010],y[300010];
int a;
std::vector<long long int> V;
long long int func(int s, int t)
{
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s1 = -1, s2 = -1, s3 = -1;
	if(x[s-1]+t!=x[s]) s1 = func(s+1,0);
	if(x[s-1]+t!=x[s]+1) s2 = func(s+1,1)+y[s];
	if(x[s-1]+t!=x[s]+2) s3 = func(s+1,2)+2*y[s];
	
	V.clear();
	V.push_back(s1);
	V.push_back(s2);
	V.push_back(s3);
	std::sort(V.begin(),V.end());
	for(int i=0;i<V.size();i++) if(V[i]!=-1) return check[s][t] = V[i];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			x[i] = b;
			y[i] = c;
		}
		
		for(int i=1;i<=a;i++) check[i][0] = check[i][1] = check[i][2] = -1;
		
		if(a==1) printf("0\n");
		else
		{
			long long int s1 = func(2,0);
			long long int s2 = func(2,1)+y[1];
			long long int s3 = func(2,2)+2*y[1];
			s3 = s3<s1?s3:s1;
			s3 = s3<s2?s3:s2;
			printf("%lld\n",s3);
		}
	}
}