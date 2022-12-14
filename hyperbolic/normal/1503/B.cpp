#include <stdio.h>
#include <vector>

int getQuery()
{
	int a;
	scanf("%d",&a);
	return a;
}
void func(int s, int t, int k)
{
	printf("%d %d %d\n",s,t,k);
	fflush(stdout);
}

std::vector< std::pair<int,int> > V1,V2;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if((i+j)%2==0) V1.push_back({i,j});
			else V2.push_back({i,j});
		}
	}
	
	int type = 0;
	for(int i=1;i<=a*a;i++)
	{
		int t = getQuery();
		if(t==1)
		{
			if(V1.size()==0) type = 1;	
		}
		else
		{
			if(V2.size()==0) type = 2;
		}
		
		if(type==0)
		{
			if(t==1)
			{
				func(3,V1.back().first,V1.back().second);
				V1.pop_back();
			}
			else
			{
				func(1,V2.back().first,V2.back().second);
				V2.pop_back();
			}
		}
		else if(type==1)
		{
			if(t==1) func(2,V2.back().first,V2.back().second);
			else func(1,V2.back().first,V2.back().second);
			V2.pop_back();
		}
		else
		{
			if(t==2) func(3,V1.back().first,V1.back().second);
			else func(2,V1.back().first,V1.back().second);
			V1.pop_back();
		}
	}
}