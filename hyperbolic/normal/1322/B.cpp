#include <stdio.h>
#include <algorithm>
int check[50],x[400010],y[400010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int p=0;p<=30;p++)
	{
		for(int i=1;i<=a;i++) y[i] = x[i]%(1<<(p+1));
		std::sort(y+1,y+a+1);
		int p1 = a+1, p2 = a;
		for(int i=1;i<=a;i++)
		{
			while(p1>i)
			{
				if(y[p1-1]+y[i]<(1<<p)) break;
				else p1--;
			}
			while(p2>=1)
			{
				if(y[p2]+y[i]<(1<<(p+1))) break;
				else p2--;
			}
			if(p1<=i) p1 = i+1;
			if(p1>p2) continue;
			check[p] += (p2-p1+1);
			check[p] %=2;
		}
		
		p1 = a+1, p2 = a;
		for(int i=1;i<=a;i++)
		{
			while(p1>i)
			{
				if(y[p1-1]+y[i]<3*(1<<p)) break;
				else p1--;
			}
			while(p2>=1)
			{
				if(y[p2]+y[i]<(1<<(p+2))) break;
				else p2--;
			}
			if(p1<=i) p1 = i+1;
			if(p1>p2) continue;
			check[p] += (p2-p1+1);
			check[p] %=2;
		}
	}
	
	int ans = 0;
	for(int p=0;p<=30;p++) ans+=(check[p]%2)*(1<<p);
	printf("%d",ans);
}