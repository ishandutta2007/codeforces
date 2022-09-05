#include<bits/stdc++.h>
using namespace std;

typedef long long s64;

int main()
{
	int a,b;
	cin>>a>>b;
	vector<int>p[2];
	int x=0;
	while(s64(x)*(x+1)/2<=a+b)++x;
	while(--x>0)
	{
		if(a>=x){a-=x;p[0].push_back(x);}
		else p[1].push_back(x);
	}
	for(int i=0;i<=1;++i)
	{
		printf("%d\n",int(p[i].size()));
		for(auto v:p[i])printf("%d ",v);puts("");
	}
}