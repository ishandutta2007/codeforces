#include<cstdio>
#include<algorithm>

int n;
char a[300][301];
int d[300];
int v[300];
int r[300];

void f(int x)
{
	if(v[x])return;
	int i;
	v[x]=1;
	for(i=0;i<n;i++)if(a[x][i]=='1')f(i);
}

int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&d[i]);
	for(i=0;i<n;i++)scanf("%s",a[i]);
	for(i=0;i<n;i++)if(!v[i])
	{
		f(i);
		k=0;
        for(j=0;j<n;j++)if(v[j])r[k++]=d[j];
        std::sort(r,r+k);
        k=0;
        for(j=0;j<n;j++)if(v[j])d[j]=r[k++];
        for(j=0;j<n;j++)v[j]=0;
	}
	for(i=0;i<n;i++)printf("%d ",d[i]);
}