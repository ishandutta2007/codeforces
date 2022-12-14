#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int second;
	int value;
};
bool cmp(str a, str b)
{
	return a.value>b.value;
}
std::vector<str> V;

int abs(int k)
{
	return k>0?k:-k;
}

char temp[30];
int getQuery(int s, int t)
{
	printf("? %d %d\n",s,t);
	fflush(stdout);
	
	scanf("%s",temp+1);
	if(temp[1]=='N') return 0;
	else return 1;
}

int x[510],check[510];
std::pair<int,int> y[510];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(x[i]>x[j]) V.push_back({i,j,abs(x[i]-x[j])});
			else V.push_back({j,i,abs(x[i]-x[j])});
		}
	}
	std::sort(V.begin(),V.end(),cmp);
	
	for(int i=0;i<V.size();i++)
	{
		int t = getQuery(V[i].first,V[i].second);
		if(t==1)
		{
			printf("! %d %d",V[i].first,V[i].second);
			fflush(stdout);
			return 0;
		}
	}
	printf("! 0 0");
	fflush(stdout);
}