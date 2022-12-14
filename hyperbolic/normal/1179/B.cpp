#include <stdio.h>

int L,R,U,D;
void func1()
{
	int p = U+1;
	for(int i=U;i<=D;i++)
	{
		if(p>D) p = U;
		printf("%d %d\n",i,L);
		printf("%d %d\n",p,R);
		p+=2;
	}
	R--,L++;
}
void func2()
{
	int p = L+1;
	for(int i=L;i<=R;i++)
	{
		if(p>R) p = L;
		printf("%d %d\n",U,i);
		printf("%d %d\n",D,p);
		p+=2;
	}
	D--,U++;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	L = 1, R = b;
	U = 1, D = a;
	while(1)
	{
		if(L>R) break;
		if(U>D) break;
		if(L==R && U==D)
		{
			printf("%d %d\n",U,L);
			break;
		}
		if(L<R) func1();
		if(U<D) func2();
	}
}