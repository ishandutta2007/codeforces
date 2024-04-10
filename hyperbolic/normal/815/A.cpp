#include <stdio.h>
#define MAX 12345678

int x[110][110];
int s1[110],s2[110];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	
	int ans = MAX;
	int ind = -1;
	
	for(int k=0;k<=x[1][1];k++)
	{
		s1[1] = k;
		s2[1] = x[1][1] - k;
		int C = 0;
		for(int j=2;j<=b;j++)
		{
			s1[j] = x[1][j] - s2[1];
			if(s1[j]<0) goto u;
		}
		for(int i=2;i<=a;i++)
		{
			s2[i] = x[i][1] -s1[1];
			if(s2[i]<0) goto u;
		}
		
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]!=s1[j]+s2[i]) goto u;
		
		for(int i=1;i<=a;i++) C += s2[i];
		for(int j=1;j<=b;j++) C += s1[j];
		if(ans>C)
		{
			ans = C;
			ind = k;
		}
		
		u:;
	}
	
	if(ans==MAX) printf("-1");
	else
	{
		printf("%d\n",ans);
		s1[1] = ind;
		s2[1] = x[1][1] - ind;
		for(int j=2;j<=b;j++) s1[j] = x[1][j] - s2[1];
		for(int i=2;i<=a;i++) s2[i] = x[i][1] -s1[1];
		
		for(int i=1;i<=a;i++) while(s2[i]--) printf("row %d\n",i);
		for(int j=1;j<=b;j++) while(s1[j]--) printf("col %d\n",j);
	}
}