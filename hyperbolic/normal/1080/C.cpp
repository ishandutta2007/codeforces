#include <stdio.h>
#include <vector>
struct str{
	long long int x0;
	long long int y0;
	long long int x1;
	long long int y1;
};

std::vector<str> white,black;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		white.clear(),black.clear();
		long long int a,b;
		int x1,y1,x2,y2,x3,y3,x4,y4;
		scanf("%lld%lld",&a,&b);
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
		
		if(x1<x3&&x4<x2)
		{
			white.push_back({x1,y1,x3-1,y2});
			white.push_back({x4+1,y1,x2,y2});
			x1 = x3, x2 = x4;
		}
		else if(x1<x3&&x3<=x2&&x2<=x4)
		{
			white.push_back({x1,y1,x3-1,y2});
			x1 = x3;
		}
		else if(x3<=x1&&x1<=x4&&x4<x2)
		{
			white.push_back({x4+1,y1,x2,y2});
			x2 = x4;
		}
		
		if(y1<y3&&y4<y2)
		{
			white.push_back({x1,y1,x2,y3-1});
			white.push_back({x1,y4+1,x2,y2});
			y1 = y3, y2 = y4;
		}
		else if(y1<y3&&y3<=y2&&y2<=y4)
		{
			white.push_back({x1,y1,x2,y3-1});
			y1 = y3;
		}
		else if(y3<=y1&&y1<=y4&&y4<y2)
		{
			white.push_back({x1,y4+1,x2,y2});
			y2 = y4;
		}
		
		if(x2<x3) white.push_back({x1,y1,x2,y2});
		else if(x4<x1) white.push_back({x1,y1,x2,y2});
		else if(y2<y3) white.push_back({x1,y1,x2,y2});
		else if(y4<y1) white.push_back({x1,y1,x2,y2});
		
		black.push_back({x3,y3,x4,y4});
		
		
		long long int W = (a*b+1)/2,B = (a*b)/2;
		for(int i=0;i<white.size();i++)
		{
			long long int s = (white[i].x1-white[i].x0+1);
			long long int t = (white[i].y1-white[i].y0+1);
			if((white[i].x0+white[i].y0)%2==0) // 1 start
			{
				W += (s*t)/2;
				B -= (s*t)/2;
			}
			else
			{
				W += (s*t+1)/2;
				B -= (s*t+1)/2;
			}
		}
		for(int i=0;i<black.size();i++)
		{
			long long int s = (black[i].x1-black[i].x0+1);
			long long int t = (black[i].y1-black[i].y0+1);
			if((black[i].x0+black[i].y0)%2==0) // 1 start
			{
				W -= (s*t+1)/2;
				B += (s*t+1)/2;
			}
			else
			{
				W -= (s*t)/2;
				B += (s*t)/2;
			}
		}
		printf("%lld %lld\n",W,B);
	}
}