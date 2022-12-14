#include <stdio.h>

int a,b,L;
int x[510],y[510];
long long int check[510][510];
long long int func(int s, int t1)
{
	if(s>a) return 0;
	if(check[s][t1]!=-1000) return check[s][t1];
	
	int t2 = (L-t1+b)%b;
	long long int ans = func(s+1,t1);
	
	for(int i=1;i<b;i++)
	{
		int j = b-i;
		if(i>x[s]||j>y[s]) continue;
		
		long long int S;
		if(i>t1 && j>t2) S = func(s+1,(t1-i+b)%b) - 1;
		else if(i>t1) S = func(s+1,(t1-i+b)%b);
		else if(j>t2) S = func(s+1,t1-i);
		else S = func(s+1,t1-i)+1;
		ans = ans>S?ans:S;
	}
	return check[s][t1] = ans;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) check[i][j] = -1000;
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	
	long long int ans = 0;
	long long int sumX = 0, sumY = 0;
	for(int i=1;i<=a;i++) sumX += x[i];
	for(int i=1;i<=a;i++) sumY += y[i];
	ans += sumX/b, ans += sumY/b;
	sumX %= b, sumY %= b;
	L = sumX + sumY;
	printf("%lld",ans+func(1,sumX));
}