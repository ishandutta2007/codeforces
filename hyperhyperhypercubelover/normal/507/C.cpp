#include<cstdio>

int main()
{
    int flag=0;
    int i,n;
    long long m,res=0;
    scanf("%d%I64d",&n,&m);
    m--;
    for(i=n-1;i>=0;i--)
	{
		if(((m>>i)&1)!=flag)res+=(2LL<<i)-1;
		else flag=!flag;
	}
    printf("%I64d",res+n);
}