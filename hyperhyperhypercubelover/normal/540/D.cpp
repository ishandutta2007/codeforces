#include<cstdio>

double d[111][111][111];

int main()
{
	int t;
    int i,j,k,n,m,l;
	scanf("%d%d%d",&n,&m,&l);
    d[n][m][l]=1.000000;
    for(t=n+m+l-1;t>0;t--)for(i=0;i<=n;i++)for(j=0;j<=m;j++)
	{
		if(i+j>t)break;
		k=t-i-j;
		if(k>l)continue;
        if((i+1)*k+k*j+j*(i+1))d[i][j][k]+=d[i+1][j][k]*(i+1)*k/((i+1)*k+k*j+j*(i+1));
        else d[i][j][k]+=d[i+1][j][k];
        if((j+1)*i+i*k+k*(j+1))d[i][j][k]+=d[i][j+1][k]*(j+1)*i/((j+1)*i+i*k+k*(j+1));
        else d[i][j][k]+=d[i][j+1][k];
        if((k+1)*j+j*i+i*(k+1))d[i][j][k]+=d[i][j][k+1]*(k+1)*j/((k+1)*j+j*i+i*(k+1));
        else d[i][j][k]+=d[i][j][k+1];
	}
	printf("%.12lf %.12lf %.12lf",d[1][0][0],d[0][1][0],d[0][0][1]);
}