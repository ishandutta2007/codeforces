#include<cstdio>

int a[201][201];
int d[201][201];
int v[201][201];
int qx[55555],qy[55555],qz[55555],qn;
char s[222];

void add(int x,int y,int z)
{
	if(x>=0&&x<=200&&y>=0&&y<=200&&a[x][y]&&!v[x][y])
	{
		v[x][y]=1;
		d[x][y]=z;
		qx[qn]=x;
		qy[qn]=y;
		qz[qn]=z;
		qn++;
	}
}

int main()
{
	int i,j,k,n;
	scanf("%s",s);
	i=j=100;
	a[i][j]=1;
	for(k=0;s[k];k++)
	{
        if(s[k]=='L')i--;
        if(s[k]=='R')i++;
        if(s[k]=='U')j--;
        if(s[k]=='D')j++;
		a[i][j]=1;
	}
	n=k;
	add(100,100,0);
    for(k=0;k<qn;k++)
	{
		add(qx[k]+1,qy[k],qz[k]+1);
		add(qx[k]-1,qy[k],qz[k]+1);
		add(qx[k],qy[k]+1,qz[k]+1);
		add(qx[k],qy[k]-1,qz[k]+1);
	}
	puts(n==d[i][j]?"OK":"BUG");
}