#include <stdio.h>
#define MAX 1e9

long long int sqrt(long long int k)
{
	long long int ans = k;
	long long int min = 1, max = k<MAX?k:MAX;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		if(h*h<=k)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		long long int l = sqrt(a);
		long long int r = sqrt(b);
		
		long long int ans = 0;
		
		if(l==r)
		{
			if(a<=l*l&&l*l<=b) ans++;
			if(a<=l*l+l&&l*l+l<=b) ans++;
			if(a<=l*l+2*l&&l*l+2*l<=b) ans++;
			printf("%lld\n",ans);
		}
		else
		{
			if(a<=l*l&&l*l<=b) ans++;
			if(a<=l*l+l&&l*l+l<=b) ans++;
			if(a<=l*l+2*l&&l*l+2*l<=b) ans++;
			l++;
			if(a<=r*r&&r*r<=b) ans++;
			if(a<=r*r+r&&r*r+r<=b) ans++;
			if(a<=r*r+2*r&&r*r+2*r<=b) ans++;
			r--;
			printf("%lld\n",ans+(r-l+1)*3);
		}
	}
}