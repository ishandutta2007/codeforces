#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int W=0,H=0,x1=0,x2=0,y1=0,y2=0,w=0,h=0;scanf("%d%d%d%d%d%d%d%d",&W,&H,&x1,&y1,&x2,&y2,&w,&h);
		if(x2-x1+w>W&&y2-y1+h>H){puts("-1");continue;}
		int ans=1e9;
		if(x2-x1+w<=W)
		{
			if(x1>=w)ans=0;else ans=min(ans,w-x1);
			if(x2<=W-w)ans=0;else ans=min(ans,x2-(W-w));
		}
		if(y2-y1+h<=H)
		{
			if(y1>=h)ans=0;else ans=min(ans,h-y1);
			if(y2<=H-h)ans=0;else ans=min(ans,y2-(H-h));
		}
		printf("%.10lf\n",(double)ans);
	}
}