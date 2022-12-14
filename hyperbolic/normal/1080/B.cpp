#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		if(b%2==0&&c%2==0) printf("%d\n",c-(c-b)/2);
		if(b%2==1&&c%2==1) printf("%d\n",-c+(c-b)/2);
		if(b%2==0&&c%2==1) printf("%d\n",-(c-b+1)/2);
		if(b%2==1&&c%2==0) printf("%d\n",(c-b+1)/2);
	}
}