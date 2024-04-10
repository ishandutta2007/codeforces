#include <stdio.h>
#include <queue>
#include <map>
#include <vector>

int y[50010][50];
int x[50010];

int a;
std::queue<int> Q;
std::map<int,int> check;
std::vector<int> ansV;
int func(int k)
{
	check.clear();
	while(!Q.empty()) Q.pop();
	
	for(int i=1;i<=a;i++)
	{
		int s = 0;
		for(int j=30;j>=0;j--)
		{
			s*=2;
			s += y[i][j];
			if(s>k)
			{
				s/=2;
				Q.push(s);
				goto u;
			}
		}
		Q.push(s);
		u:;
	}
	
	while(!Q.empty())
	{
		int C = Q.front();
		Q.pop();
		if(C==0) return 0;
		
		if(check[C]==0) check[C] = 1;
		else
		{
			if(C==0) return 0;
			else Q.push(C/2);
		}
	}
	
	ansV.clear();
	for(std::map<int,int> ::iterator it = check.begin();it!=check.end();it++)
	{
		ansV.push_back((it->first));
	}
	return 1;
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) for(int j=0;j<=30;j++) y[i][j] = x[i]%2, x[i]/=2;
	
	int min = 0, max = 1000000000;
	int ans = 1000000000;
	while(min<=max)
	{
		int h = (min+max)/2;
		int k = func(h);
		if(k==1)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	for(int i=0;i<ansV.size();i++) printf("%d ",ansV[i]);
}