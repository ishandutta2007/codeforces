#include <stdio.h>
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a,b,c,d,i,s,t;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=1;i<=100000;i++)
	{
		s=c-i;
		t=d-i;
		if(s<0) s=0;
		if(t<0) t=0;
		if(abs(a-s)+abs(b-t)<=i)
		{
			printf("Polycarp");
			return 0;
		}
		if(s==0&&t==0) break;
	}
	printf("Vasiliy");
}