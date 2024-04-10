#include <stdio.h>
#define MOD 32768

int check[40010][20];
int func(int k, int cnt)
{
	if(cnt>16) return 12345678;
	if(k==0) return cnt;
	if(check[k][cnt]!=-1) return check[k][cnt];
	
	int s1 = func((k+1)%MOD,cnt+1);
	int s2 = func((k*2)%MOD,cnt+1);
	return check[k][cnt] = s1<s2?s1:s2;
}

int main()
{
	for(int i=0;i<=MOD;i++) for(int j=0;j<=16;j++) check[i][j] = -1;
	
	int a;
	scanf("%d",&a);
	while(a--)
	{
		int b;
		scanf("%d",&b);
		printf("%d\n",func(b,0));
	}
}