#include <stdio.h>
#include <vector>
#include <algorithm>

char x[1000010],y[1000010];
std::vector<int> V,W;
std::pair<int,int> check;
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	x[a+1] = '1';
	
	int start = 1;
	while(x[start]=='0') start++;
	if(start>a)
	{
		printf("0");
	}
	
	for(int i=start;i<=a;i++) V.push_back(1-(x[i]-'0'));
	while(V.size()>60) V.pop_back();
	
	long long int S = 0;
	for(int i=0;i<V.size();i++) S*=2, S+=V[i];
	
	int n = V.size();
	int last = start+60-1<a?start+60-1:a;
	long long int ans = 0;
	
	for(int i=1;i<=a;i++)
	{
		long long int t = 0;
		for(int j=i;j<=i+60-1&&j<=last;j++)
		{
			t*=2, t+=x[j]-'0';
			if(ans<(t&S))
			{
				ans = (t&S);
				check = std::make_pair(i,j);
			}
		}
	}
	
	int p1 = check.first;
	int p2 = last - (check.second - check.first);
	for(int i=1;i<=a;i++) y[i] = x[i];
	while(p1<=a && p2<=a)
	{
		if(x[p1]=='1') y[p2] = '1';
		p1++, p2++;
	}
	for(int i=start;i<=a;i++) printf("%c",y[i]);
}