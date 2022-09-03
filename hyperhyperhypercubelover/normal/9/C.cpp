#include<cstdio>

int f(int x)
{
    int i,j,res=0;
    for(i=j=1;i<=x;i*=2,j*=10);
	for(i/=2,j/=10;i;i/=2,j/=10)res+=x/i%2*j;
	return res;
}

int main()
{
	int i,n;
    scanf("%d",&n);
    for(i=1;f(i)<=n;i++);
    printf("%d",i-1);
}