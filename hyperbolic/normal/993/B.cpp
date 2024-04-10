#include <stdio.h>
#include <vector>

std::pair<int,int> P1[110],P2[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c<=d) P1[i] = std::make_pair(c,d);
		else P1[i] = std::make_pair(d,c);
	}
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c<=d) P2[i] = std::make_pair(c,d);
		else P2[i] = std::make_pair(d,c);
	}
	
	int control = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(P1[i].first==P2[j].first && P1[i].second==P2[j].second) continue;
			else if(P1[i].first==P2[j].first)
			{
				if(control==0) control = P1[i].first;
				else if(control != P1[i].first) control = -1;
			}
			else if(P1[i].second==P2[j].second)
			{
				if(control==0) control = P1[i].second;
				else if(control != P1[i].second) control = -1;
			}
			else if(P1[i].first==P2[j].second)
			{
				if(control==0) control = P1[i].first;
				else if(control != P1[i].first) control = -1;
			}
			else if(P1[i].second==P2[j].first)
			{
				if(control==0) control = P1[i].second;
				else if(control != P1[i].second) control = -1;
			}
		}
	}
	
	int control2 = 0;
	
	for(int i=1;i<=a;i++)
	{
		int control = 0;
		for(int j=1;j<=b;j++)
		{
			if(P1[i].first==P2[j].first && P1[i].second==P2[j].second) continue;
			else if(P1[i].first==P2[j].first)
			{
				if(control==0) control = P1[i].first;
				else if(control != P1[i].first) control = -1;
			}
			else if(P1[i].second==P2[j].second)
			{
				if(control==0) control = P1[i].second;
				else if(control != P1[i].second) control = -1;
			}
			else if(P1[i].first==P2[j].second)
			{
				if(control==0) control = P1[i].first;
				else if(control != P1[i].first) control = -1;
			}
			else if(P1[i].second==P2[j].first)
			{
				if(control==0) control = P1[i].second;
				else if(control != P1[i].second) control = -1;
			}
		}
		if(control==-1) control2 = 1;
	}
	
	for(int j=1;j<=b;j++)
	{
		int control = 0;
		for(int i=1;i<=a;i++)
		{
			if(P1[i].first==P2[j].first && P1[i].second==P2[j].second) continue;
			else if(P1[i].first==P2[j].first)
			{
				if(control==0) control = P1[i].first;
				else if(control != P1[i].first) control = -1;
			}
			else if(P1[i].second==P2[j].second)
			{
				if(control==0) control = P1[i].second;
				else if(control != P1[i].second) control = -1;
			}
			else if(P1[i].first==P2[j].second)
			{
				if(control==0) control = P1[i].first;
				else if(control != P1[i].first) control = -1;
			}
			else if(P1[i].second==P2[j].first)
			{
				if(control==0) control = P1[i].second;
				else if(control != P1[i].second) control = -1;
			}
		}
		if(control==-1) control2 = 1;
	}
	
	if(control==0) printf("-1");
	else if(control>0) printf("%d",control);
	else
	{
		if(control2==1) printf("-1");
		else printf("0");
	}
}