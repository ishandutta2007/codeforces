#include<cstdio>

int f(int a,int b){return a?f(b%a,a):b;}

int main()
{
    int i,j,a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",b*(6*a-1));
    j=2;
    for(i=0;i<a;i++)
	{
		printf("%d %d %d ",b*(6*i+1),b*(6*i+3),b*(6*i+5));
		while(f(j,6*i+1)>1||f(j,6*i+3)>1||f(j,6*i+5)>1)j+=2;
		printf("%d\n",b*j);
		j+=2;
	}
}