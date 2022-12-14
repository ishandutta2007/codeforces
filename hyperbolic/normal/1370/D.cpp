#include <stdio.h>
#include <vector>
std::vector<int> V;
int x[200010],a;
int func(int s, int t, int h)
{
	if(s>a) return 0;
	if(t==1)
	{
		if(x[s]<=h) return func(s+1,0,h)+1;
		else return func(s+1,1,h);
	}
	else return func(s+1,1,h)+1;
}
int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int min = 1, max = 1000000000;
	int ans = 1234567890;
	while(min<=max)
	{
		int h = (min+max)/2;
		int s1 = func(1,1,h);
		int s2 = func(1,0,h);
		if(s1>=b || s2>=b)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	printf("%d",ans);
}