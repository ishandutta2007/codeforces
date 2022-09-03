#include<cstdio>

const int mod = 1000000007;

char s[5555];
int a[5555][5555];
int d[5555][5555];

int main()
{
    int i,j,n;
    scanf("%d%s",&n,s);
	for(i=n-1;i>=0;i--)for(j=n-1;j>i;j--)
	{
		if(s[i]>s[j])a[i][j]=-1;
		else if(s[i]<s[j])a[i][j]=i;
		else if(j==n-1)a[i][j]=-1;
		else a[i][j]=a[i+1][j+1];
	}
	for(j=0;j<n;j++)d[0][j]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(j)d[i][j]=d[i][j-1];
			if(j&&s[i-j]!='0')(d[i][j]+=d[i-j-1][j-1])%=mod;
			if(i-j-j-1>=0&&s[i-j]!='0'&&a[i-j-j-1][i-j]>=0&&a[i-j-j-1][i-j]<i-j)
			{
				(d[i][j]+=d[i-j-1][j])%=mod;
				if(j)(d[i][j]+=mod-d[i-j-1][j-1])%=mod;
			}
		}
        d[i][i]=(d[i][i-1]+1)%mod;
        for(j=i+1;j<n;j++)d[i][j]=d[i][j-1];
	}
	printf("%d",d[n-1][n-1]);
}