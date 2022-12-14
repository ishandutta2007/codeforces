#include <stdio.h>
long long int x[510][510];
int main()
{
    int a,x0,y0;
    scanf("%d",&a);
    if(a==1)
    {
		printf("1");
		return 0;
    }
    for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%I64d",&x[i][j]);
    for(int i=1;i<=a;i++)
    {
		for(int j=1;j<=a;j++)
		{
			if(x[i][j]==0)
			{
				x0 = i;
				y0 = j;
			}
		}
    }
    long long int s = 0;
    long long int ans = -1;
    if(x0==1)
    {
		long long int s2 = 0;
        for(int i=1;i<=a;i++) s+=x[2][i];
        for(int i=1;i<=a;i++) s2+=x[x0][i];
        ans = s-s2;
        x[x0][y0] = ans;
    }
    else
    {
		long long int s2 = 0;
        for(int i=1;i<=a;i++) s+=x[1][i];
        for(int i=1;i<=a;i++) s2+=x[x0][i];
        ans = s-s2;
        x[x0][y0] = ans;
    }

    if(ans<=0)
    {
		printf("-1");
		return 0;
    }
    for(int i=1;i<=a;i++)
    {
		long long int s2 = 0;
		for(int j=1;j<=a;j++) s2+=x[i][j];
		if(s!=s2)
		{
			printf("-1");
			return 0;
		}
    }

    for(int j=1;j<=a;j++)
    {
		long long int s2 = 0;
		for(int i=1;i<=a;i++) s2+=x[i][j];
		if(s!=s2)
		{
			printf("-1");
			return 0;
		}
    }

    long long int s3 = 0;
    for(int i=1;i<=a;i++) s3+=x[i][i];
    if(s!=s3)
    {
		printf("-1");
		return 0;
    }

    long long int s4 = 0;
    for(int i=1;i<=a;i++) s4+=x[i][a-i+1];
    if(s!=s4)
    {
		printf("-1");
		return 0;
    }

    printf("%I64d",ans);
}