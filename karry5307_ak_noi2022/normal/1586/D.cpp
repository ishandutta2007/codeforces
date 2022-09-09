#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int pos[200];
int a[200];

int query_P(int p)
{
	if(p==n)return 0;
	printf("? ");for(int i=1;i<n;i++)printf("%d ",p+1);printf("%d ",1);puts("");fflush(stdout);
	int x=0;scanf("%d",&x);return x;
}
int query_N(int p)
{
	printf("? ");for(int i=1;i<n;i++)printf("%d ",1);printf("%d ",1+p);puts("");fflush(stdout);
	int x=0;scanf("%d",&x);return x;
}

int main()
{
	scanf("%d",&n);
	int p=1;while(pos[p]=query_P(p)){p++;}
	a[n]=p;for(int i=1;i<p;i++)a[pos[i]]=p-i;
	for(int i=1;i+p<=n;i++)
	{
		a[query_N(i)]=i+p;
	}
	printf("! ");for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");fflush(stdout);
}