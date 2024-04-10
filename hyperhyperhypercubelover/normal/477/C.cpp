#include<cstdio>
#include<cstring>
#include<algorithm>

char a[2222];
char b[555];
int d[2222][2222];

int main()
{
	int i,j,k,n,m;
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for(i=1;i<=n;i++)
	{
		k=m;
        for(j=i;j>0&&k;j--)if(a[j]==b[k])k--;
        if(k==0)for(k=0;k<=i;k++)if(k+j-i+m>=0)d[i][k]+=d[j][k+j-i+m]+1;
        for(k=0;k<=i;k++)
		{
			if(d[i][k]<d[i-1][k])d[i][k]=d[i-1][k];
			if(d[i][k]<d[i][k-1])d[i][k]=d[i][k-1];
		}
	}
    for(i=0;i<=n;i++)printf("%d ",std::min(d[n][i],(n-i)/m));
}