#include<cstdio>
bool sqr[100000010];
void process(void) {
	int i,j,n,c;
	for (i=1;i<=10000;i=i+1)
		sqr[i*i]=true;
	c=0;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1)
		for (j=i;i*i+j*j<=n*n;j=j+1)
			if (sqr[i*i+j*j]) c++;
	printf("%d",c);
}
int main(void) {
	process();
	return 0;
}