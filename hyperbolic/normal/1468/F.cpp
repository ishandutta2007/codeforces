#include <stdio.h>
#include <algorithm>
#include <map>

struct str{
	int x0;
	int y0;
};
bool operator<(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}
std::map<str,int> M;
int abs(int k)
{
	return k>0?k:-k;
}
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		long long int ans = 0;
		
		for(int i=1;i<=a;i++)
		{
			int b,c,d,e;
			scanf("%d%d%d%d",&b,&c,&d,&e);
			int g = gcd(abs(d-b),abs(e-c));
			int s = (d-b)/g;
			int t = (e-c)/g;
			ans += M[{-s,-t}];
			M[{s,t}]++;
		}
		printf("%lld\n",ans);
	}
}