#include<cstdio>

#define MOD 1000000007

int a[11];
int d[11][101];

int c[1000][1000];

int main()
{
	int t;
	int i,j,k,l,n;
	scanf("%d",&n);
	for(i=0;i<10;i++)scanf("%d",&a[(i+9)%10+1]);
	for(i=0;i<1000;i++)c[i][0]=c[i][i]=1;
    for(i=1;i<1000;i++)for(j=1;j<i;j++)(c[i][j]=c[i-1][j]+c[i-1][j-1])%=MOD;
    d[0][0]=1;
    for(i=1;i<=10;i++)for(j=0;j<=n;j++)for(k=a[i];i<10?k<=j:k<j;k++)(d[i][j]+=1LL*d[i-1][j-k]*c[i<10?j:j-1][k]%MOD)%=MOD;
    t=0;
    for(i=1;i<=n;i++)(t+=d[10][i])%=MOD;
    printf("%d",t);
}