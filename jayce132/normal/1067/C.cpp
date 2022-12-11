#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int m2;
	for(m2=1;m2<=(n-m2)*2;m2++);
	for(int i=1;i<=m2;i++)printf("%d %d\n",1,i);
	for(int i=1;i<=n-m2;i++)printf("%d %d\n",4,i*2+1);
	return 0;
}