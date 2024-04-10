#include <stdio.h>

char x[100010];
char y[110];
int func(int k)
{
	if(x[k]=='a'&&x[k+1]=='b'&&x[k+2]=='c') return 1;
	else return 0;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	
	int ans = 0;
	for(int i=1;i<=a-2;i++) ans += func(i);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		scanf("%s",y+1);
		if(c-2>=1&&c+0<=a) ans -= func(c-2);
		if(c-1>=1&&c+1<=a) ans -= func(c-1);
		if(c-0>=1&&c+2<=a) ans -= func(c);
		x[c] = y[1];
		
		if(c-2>=1&&c+0<=a) ans += func(c-2);
		if(c-1>=1&&c+1<=a) ans += func(c-1);
		if(c-0>=1&&c+2<=a) ans += func(c);
		printf("%d\n",ans);
	}
}