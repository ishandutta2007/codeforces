#include <stdio.h>
int x[10];
int func()
{
	int m = x[1];
	m = m<x[2]?m:x[2];
	m = m<x[3]?m:x[3];
	if(m==x[1]) return 1;
	if(m==x[2]) return 2;
	if(m==x[3]) return 3;
}
int main()
{
	int a,b,count=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=3;i++) x[i]=b;
    while(1)
    {
        int k = func();
        if(x[k]==a) break;
        x[k] = x[1]+x[2]+x[3]-x[k]-1;
        if(x[k]>a) x[k]=a;
        count++;
    }
    printf("%d",count);
}