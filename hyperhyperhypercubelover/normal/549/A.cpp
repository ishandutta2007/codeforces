#include<cstdio>

char a[55][55];
int t[555];

int main()
{
	int i,j,k,n,m,r=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",a[i]);
	for(i=1;i<n;i++)for(j=1;j<m;j++)
	{
		for(k=0;k<555;k++)t[k]=0;
        t[a[i-1][j-1]]++;
        t[a[i][j-1]]++;
        t[a[i-1][j]]++;
        t[a[i][j]]++;
        if(t['a']&&t['c']&&t['e']&&t['f'])r++;
	}
	printf("%d",r);
}