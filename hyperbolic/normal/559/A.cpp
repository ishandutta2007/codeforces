#include <stdio.h>

int main()
{
	int a,b,c,d,e,f;
	int s1=0,s2=0,s3=0,i,m1,m2;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	// b e
	m1 = a<c?a:c;
	m2 = d<f?d:f;
	// 2*b+1 + 2*(b+1) +1 ....2*(b+m1-1)+1
	for(i=b;i<b+m1;i++) s1+=2*i+1;
	// 2*e+1 + 2*(e+1) +1 ...2*(e+m2-1)+1
	for(i=e;i<e+m2;i++) s2+=2*i+1;
	s3 = (d+c-m2-m1)*2*(b+m1);
	//printf("%d %d %d\n",s1,s2,s3);
	printf("%d",s1+s2+s3);
}