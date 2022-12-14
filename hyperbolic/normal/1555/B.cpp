#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int W,H;
		scanf("%lld%lld",&W,&H);
		long long int x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		long long int w,h;
		scanf("%lld%lld",&w,&h);
		
		long long int ans = 1234567890,ans1 = 1234567890, ans2 = 1234567890;
		long long int t;
		t = h-y1;
		if(t<=0)
		{
			printf("0\n");
			continue;
		}
		ans1 = ans1<t?ans1:t;
		t = y2-(H-h);
		if(t<=0)
		{
			printf("0\n");
			continue;
		}
		ans1 = ans1<t?ans1:t;
			
		t = w-x1;
		if(t<=0)
		{
			printf("0\n");
			continue;
		}
		ans2 = ans2<t?ans2:t;
		t = x2-(W-w);
		if(t<=0)
		{
			printf("0\n");
			continue;
		}
		ans2 = ans2<t?ans2:t;
		
		if(w+(x2-x1)<=W) ans = ans<ans2?ans:ans2;
		if(h+(y2-y1)<=H) ans = ans<ans1?ans:ans1;
		if(ans==1234567890) printf("-1\n");
		else printf("%lld\n",ans);
	}
}