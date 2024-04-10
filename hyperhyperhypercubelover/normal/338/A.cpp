#include<cstdio>

int calc(int y)
{
	if(y==0)return 1;
	if(y&1)return 2LL*calc(y-1)%1000000009;
    int t=calc(y>>1);
    return 1LL*t*t%1000000009;
}

int main()
{
	long long r=0;
	long long x,y,z;
	scanf("%I64d%I64d%I64d",&x,&y,&z);
	if((y+z-2)/(z-1)<=x-y-1)r=y;
	else
	{
		r+=(x-y)*(z-1);
		y-=r;
        x-=r/(z-1)*z;
		r+=2LL*(calc(y/z)-1)*z;
		r+=y%z;
	}
	printf("%I64d",r%1000000009);
	return 0;
}