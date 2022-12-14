#include <stdio.h>
#include <vector>
#include <algorithm>

int check[110][110][110];
int next[110][110][110];
int a;
int x[110];

int func(int k, int s, int t)
{
	if(k==a)
	{
		int s1 = x[a] - x[s];
		int s2 = x[a] - x[t];
		return s1>s2?s1:s2;
	}
	if(check[k][s][t]!=-1) return check[k][s][t];
	
	int s1 = func(k+1,k,t);
	s1 = s1>x[k]-x[s]?s1:x[k]-x[s];
	int s2 = func(k+1,s,k);
	s2 = s2>x[k]-x[t]?s2:x[k]-x[t];
	if(s1<s2)
	{
		next[k][s][t] = 1;
		return check[k][s][t] = s1;
	}
	else
	{
		next[k][s][t] = 2;
		return check[k][s][t] = s2;
	}
}

std::vector<int> V1,V2;
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) for(int k=1;k<=a;k++) check[i][j][k] = -1;
	
	std::sort(x+1,x+a+1);
	func(2,1,1);
	int k = 2, s = 1, t = 1;
	while(k<a)
	{
		if(next[k][s][t]==1)
		{
			V1.push_back(x[k]);
			s = k;
		}
		else
		{
			V2.push_back(x[k]);
			t = k;
		}
		k = k+1;
	}
	printf("%d ",x[1]);
	for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
	printf("%d ",x[a]);
	for(int i=V2.size()-1;i>=0;i--) printf("%d ",V2[i]);
}