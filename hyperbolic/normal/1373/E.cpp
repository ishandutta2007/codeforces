#include <stdio.h>
#include <vector>

int a,b;
std::vector<int> V,ans,MAX;
std::vector<int> func(int s, int t)
{
	std::vector<int> V2;
	if(t==0)
	{
		if(s>=(9-b+t))
		{
			V2.push_back(9-b+t);
			s -= (9-b+t);
			while(s>=9) V2.push_back(9),s-=9;
			if(s>0) V2.push_back(s);
			return V2;
		}
		else
		{
			V2.push_back(s);
			return V2;
		}
	}
	else
	{
		if(s>=(9-b+t))
		{
			V2.push_back(9-b+t);
			s -= (9-b+t);
			if(s>=8)
			{
				V2.push_back(8);
				s-=8;
				while(s>=9) V2.push_back(9),s-=9;
				if(s>0) V2.push_back(s);
				return V2;
			}
			else if(s>0) V2.push_back(s);
			return V2;
		}
		else
		{
			V2 = MAX;
			return V2;
		}
	}
}
int main()
{
	for(int i=0;i<=100;i++) MAX.push_back(9);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		scanf("%d%d",&a,&b);
		if(a<b*(b+1)/2)
		{
			printf("-1\n");
			continue;
		}
		
		ans = MAX;
		for(int i=0;i<=b;i++)
		{
			int C = (a+9*i)-(b*(b+1)/2);
			if(C>=0 && C%(b+1)==0)
			{
				V = func(C/(b+1),i);
				if(ans.size()==0) ans = V;
				else
				{
					if(V.size()<ans.size()) ans = V;
					else if(V.size()==ans.size())
					{
						for(int j=V.size()-1;j>=0;j--)
						{
							if(V[j]<ans[j])
							{
								ans = V;
								goto u;
							}
							else if(V[j]>ans[j]) goto u;
						}
					}
				}
				u:;
			}
		}
		if(ans==MAX) printf("-1\n");
		else
		{
			for(int i=ans.size()-1;i>=0;i--) printf("%d",ans[i]);
			printf("\n");
		}
	}
}