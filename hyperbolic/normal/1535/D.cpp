#include <stdio.h>

int sum[2000010];
char x[2000010];
int b;
void update(int k)
{
	if(k==0) return;
	if(x[b-k]=='0') sum[k] = sum[2*k+1];
	else if(x[b-k]=='1') sum[k] = sum[2*k];
	else sum[k] = sum[2*k]+sum[2*k+1];
	update(k/2);
}

char y[3];
int main()
{
	int a;
	scanf("%d",&a);
	b = (1<<a);
	scanf("%s",x+1);
	for(int i=b;i<2*b;i++) sum[i] = 1;
	for(int i=b-1;i>=1;i--) update(i);
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		scanf("%s",y+1);
		x[d] = y[1];
		update(b-d);
		printf("%d\n",sum[1]);
	}
}