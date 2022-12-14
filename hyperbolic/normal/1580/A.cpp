#include <stdio.h>

char x[410][410];
int y[410][410];
int count1[410],count2[410];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = x[i][j] - '0';
		for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) y[i][j] += y[i-1][j];
		
		int ans = 123456789;
		for(int i=1;i<=a;i++)
		{
			for(int k=i+4;k<=a;k++)
			{
				for(int j=1;j<=b;j++)
				{
					count1[j] = (y[k-1][j] - y[i][j]); // make 0
					if(y[i][j]-y[i-1][j]==0) count1[j]++;
					if(y[k][j]-y[k-1][j]==0) count1[j]++;
					
					count2[j] = (k-i-1) - (y[k-1][j] - y[i][j]); // make 1
				}
				
				int s1 = count2[b-2], s2 = count1[b-2] + count2[b-1], s3 = count1[b-2] + count1[b-1] + count2[b];
				for(int j=b-3;j>=1;j--)
				{
					ans = ans<(s3+count2[j])?ans:s3+count2[j];
					s3 = s3<s2? s3:s2;
					s2 = s2<s1? s2:s1;
					s2 += count1[j], s3 += count1[j];
					s1 = count2[j];
				}
			}
		}
		printf("%d\n",ans);
	}
}