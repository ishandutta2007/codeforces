#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#define MAX 1234567890

bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	return A.first<B.first;
}
std::pair<int,int> check1[150010],check2[150010],check3[150010],check4[150010];
int x[150010],y[1500010],z[150010],w[150010];
int ans1[150010],ans2[150010],ans3[150010],ans4[150010];
std::set<int> S1[150010],S2[150010],S3[150010],S4[150010];

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	for(int i=1;i<=c;i++) scanf("%d",&z[i]);
	for(int i=1;i<=d;i++) scanf("%d",&w[i]);
	
	for(int i=1;i<=a;i++) ans1[i] = MAX;
	for(int i=1;i<=b;i++) ans2[i] = MAX;
	for(int i=1;i<=c;i++) ans3[i] = MAX;
	for(int i=1;i<=d;i++) ans4[i] = MAX;
	
	int e;
	for(int i=1;i<=a;i++) ans1[i] = x[i];
	
	scanf("%d",&e);
	for(int i=1;i<=e;i++)
	{
		int f,g;
		scanf("%d%d",&f,&g);
		S1[f].insert(g);
	}
	for(int i=1;i<=a;i++) check1[i] = std::make_pair(ans1[i],i);
	std::sort(check1+1,check1+a+1,cmp);
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(S1[check1[j].second].find(i)==S1[check1[j].second].end())
			{
				ans2[i] = y[i] + check1[j].first;
				break;
			}
		}
	}
	
	scanf("%d",&e);
	for(int i=1;i<=e;i++)
	{
		int f,g;
		scanf("%d%d",&f,&g);
		S2[f].insert(g);
	}
	for(int i=1;i<=b;i++) check2[i] = std::make_pair(ans2[i],i);
	std::sort(check2+1,check2+b+1,cmp);
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(S2[check2[j].second].find(i)==S2[check2[j].second].end())
			{
				ans3[i] = z[i] + check2[j].first;
				break;
			}
		}
	}
	
	scanf("%d",&e);
	for(int i=1;i<=e;i++)
	{
		int f,g;
		scanf("%d%d",&f,&g);
		S3[f].insert(g);
	}
	for(int i=1;i<=c;i++) check3[i] = std::make_pair(ans3[i],i);
	std::sort(check3+1,check3+c+1,cmp);
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(S3[check3[j].second].find(i)==S3[check3[j].second].end())
			{
				ans4[i] = w[i] + check3[j].first;
				break;
			}
		}
	}
	
	int min = MAX;
	for(int i=1;i<=d;i++) min = min<ans4[i]?min:ans4[i];
	if(min==MAX) printf("-1");
	else printf("%d",min);
}