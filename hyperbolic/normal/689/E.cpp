#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
struct str{
	int x0;
	int y0;
}x[1000010];
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}
long long int inv(long long int k)
{
	long long int p = MOD-2;
	long long int s = 1;
	long long int t = k;
	while(p)
	{
		if(p%2==1) s = s*t%MOD;
		t=t*t;
		t%=MOD;
		p/=2;
	}
	return s;
}
long long int check[200010];
long long int comb(int a, int b)
{
	if(b==0) return 1;
	if(a==b) return 1;
	else if(check[a]) return check[a];
	else return check[a] = (comb(a-1,b)*a%MOD)*inv(a-b)%MOD;
}
int t = 1;
int main()
{
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%d%d",&c,&d);
		x[t].x0 = c;
		x[t].y0 = 1;
		t++;
		x[t].x0 = d+1;
		x[t].y0 = -1;
		t++;
	}
	std::sort(x+1,x+t,cmp);
	int count = 0,s=1;
	long long int ans = 0;
	for(int i=1;;)
	{
		if(i>=t) break;
		s = i;
		while(s<t&&x[s].x0==x[i].x0) count+=x[s].y0,s++;		
		if(count>=b) ans+=comb(count,b)*(x[s].x0-x[i].x0);
		ans%=MOD;
		i = s;
	}
	printf("%I64d",ans);
}