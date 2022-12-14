#include <stdio.h>
#include <vector>

long long int MAX = 1;
int control = 1;
long long int ans = 0;
int k,a;

std::pair<int,int> P[100010];
void func(long long int r)
{
	while(1)
	{
		k++;
		if(k>a) return;
		if(P[k].first==1)
		{
			long long int r2 = r*P[k].second;
			if(r2>=MAX) r2 = MAX;
			func(r2);
		}
		else if(P[k].first==2) return;
		else if(P[k].first==3)
		{
			if(ans+r>=MAX)
			{
				control = 0;
				ans = MAX;
			}
			else ans+= r;
		}
	}
}

char x[10];
int main()
{
	for(int i=1;i<=32;i++) MAX*=2;
	scanf("%d",&a);
	
	int r = 1;
	int sum = a;
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		if(x[1]=='f')
		{
			int b;
			scanf("%d",&b);
			P[i] = std::make_pair(1,b);
		}
		else if(x[1]=='e') P[i] = std::make_pair(2,0);
		else P[i] = std::make_pair(3,0);
	}
	control = 1, ans = 0, k = 0;
	func(1);
	if(control==0) printf("OVERFLOW!!!");
	else printf("%lld",ans);
}