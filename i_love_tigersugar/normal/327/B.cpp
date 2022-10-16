#include<cstdio>
const int MAX=100000;
const int MAXV=10000000;
bool f[MAXV+10];
int a[MAX+10];
int n,c;
void answer(void) {
	int i,j;
	for (i=1;i<=MAXV;i=i+1) f[i]=true;
	c=0;
	for (i=5;i<=MAXV;i=i+1) 
		if (f[i]) {
			c++;
			a[c]=i;
			if (c>=MAX) {
				//printf("Success\n");
				return;
			}	
			for (j=2*i;j<=MAXV;j=j+i) f[j]=false;
		}
}
void process(void) {
	scanf("%d",&n);
	int i;
	for (i=1;i<n;i=i+1) printf("%d ",a[i]);
	printf("%d",a[n]);
}
int main(void) {
	//printf("Start\n");
	answer();
	process();
	return 0;
}