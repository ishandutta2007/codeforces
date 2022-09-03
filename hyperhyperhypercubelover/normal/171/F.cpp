#include<cstdio>

bool prime(int x)
{
	int i;
	if(x==1)return false;
	for(i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}

int rev(int x)
{
	int res=0;
	while(x)
	{
		res=res*10+x%10;
		x/=10;
	}
	return res;
}

int main()
{
	int i=2,j;
	scanf("%d",&j);
	while(j)
	{
		if(prime(i)&&prime(rev(i))&&i!=rev(i))
			j--;
		i++;
	}
	printf("%d",i-1);
}