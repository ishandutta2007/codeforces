#include<cstdio>

int chk(long long x)
{
	int t=0;
	while(x)
	{
		if(x%10==4||x%10==7)t++;
		x/=10;
	}
	return t==4||t==7;
}

int main()
{
    long long a;
    scanf("%I64d",&a);
    printf(chk(a)?"YES":"NO");
}