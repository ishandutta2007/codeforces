#include <stdio.h>
#define MAX 1234567890
int min(int a, int b)
{
	return a<b?a:b;
}
int main()
{
	int a;
	int r1, s1, p1;
	int r2, s2, p2;
	scanf("%d",&a);
	scanf("%d%d%d",&r1,&s1,&p1);
	scanf("%d%d%d",&r2,&s2,&p2);
	
	int M = min(r1,s2) + min(s1,p2) + min(p1,r2);
	int ans = a;
	
	int a1,a2,a3;
	int b1,b2,b3;
	int c1,c2,c3;
	//case 1
	if(s1-r2+r1==s2-p1+p2)
	{
		int R = MAX, L = 0;
		R = R<r1?R:r1;
		R = R<p2?R:p2;
		L = L>p2-p1?L:p2-p1;
		L = L>r1-r2?L:r1-r2;
		R = R<s1-r2+r1?R:s1-r2+r1;
		if(L<=R) ans = 0;
	}
	// case 2
	if(s1-r2-s2 == p2-r1-p1)
	{
		c2 = s1-r2-s2;
		if(c2>0) ans = ans<c2?ans:c2;
	}
	// case 3
	if(s2-s1-p1 == r1-r2-p2)
	{
		b1 = s2-s1-p1;
		if(b1>0) ans = ans<b1?ans:b1;
	}
	// case 4
	if(r2-r1-s1 == p1-s2-p2)
	{
		a3 = r2-r1-s1;
		if(a3>0) ans = ans<a3?ans:a3;
	}
	printf("%d %d",ans,M);
}