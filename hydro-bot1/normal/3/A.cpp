// Hydro submission #61f544d18c1511038a91598e@1643463890543
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int x1=s1[0]-'a'+1,y1=s1[1]-'0',x2=s2[0]-'a'+1,y2=s2[1]-'0';
	int dis=max(abs(x1-x2),abs(y1-y2));
	cout<<dis<<endl;
	while(dis--)
	{
		if(x1>x2 && y1>y2)
		{
			x1--;
			y1--;
			printf("LD\n");
			continue;
		}
		if(x1>x2 && y1==y2)
		{
			x1--;
			printf("L\n");
			continue;
		}
		if(x1>x2 && y1<y2)
		{
			x1--;
			y1++;
			printf("LU\n");
			continue;
		}
		if(x1==x2 && y1>y2)
		{
			y1--;
			printf("D\n");
			continue;
		}
		if(x1==x2 && y1<y2)
		{
			y1++;
			printf("U\n");
			continue;
		}
		if(x1<x2 && y1>y2)
		{
			x1++;
			y1--;
			printf("RD\n");
			continue;
		}
		if(x1<x2 && y1==y2)
		{
			x1++;
			printf("R\n");
			continue;
		}
		if(x1<x2 && y1<y2)
		{
			x1++;
			y1++;
			printf("RU\n");
			continue;
		}
	}
	return 0;
}