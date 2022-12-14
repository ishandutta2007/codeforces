#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int func2(int a, int b, int c, int d, int e, int f)
{
	int s1 = a*d + c*f + e*b;
	int s2 = b*c + d*e + f*a;
	return abs(s1-s2);
}

int func(int a, int b, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int s1 = func2(a,b,x1,y1,x2,y2) + func2(a,b,x2,y2,x3,y3) + func2(a,b,x3,y3,x4,y4) + func2(a,b,x4,y4,x1,y1);
	int s2 = 2*((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	
	if(s1==s2) return 1;
	else return 0;
}
int main()
{
	int x1,y1,x2,y2,x3,y3,x4,y4;
	int a1,b1,a2,b2,a3,b3,a4,b4;
	scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	scanf("%d%d%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3,&a4,&b4);
	
	if(func(a1,b1,x1,y1,x2,y2,x3,y3,x4,y4)) printf("YES");
	else if(func(a2,b2,x1,y1,x2,y2,x3,y3,x4,y4)) printf("YES");
	else if(func(a3,b3,x1,y1,x2,y2,x3,y3,x4,y4)) printf("YES");
	else if(func(a4,b4,x1,y1,x2,y2,x3,y3,x4,y4)) printf("YES");
	else if(func(x1,y1,a1,b1,a2,b2,a3,b3,a4,b4)) printf("YES");
	else if(func(x2,y2,a1,b1,a2,b2,a3,b3,a4,b4)) printf("YES");
	else if(func(x3,y3,a1,b1,a2,b2,a3,b3,a4,b4)) printf("YES");
	else if(func(x4,y4,a1,b1,a2,b2,a3,b3,a4,b4)) printf("YES");
	else if(func((a1+a2+a3+a4)/4,(b1+b2+b3+b4)/4,x1,y1,x2,y2,x3,y3,x4,y4)) printf("YES");
	else printf("NO");
}