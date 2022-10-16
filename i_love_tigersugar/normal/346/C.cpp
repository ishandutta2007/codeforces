#include<cstdio>
#include<algorithm>
#define MAX   1000100
using namespace std;
int a[MAX];
int next[MAX];
int jump[MAX];
int n,f,l;
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
void count(const int &x) {
	int fst;
	if (f%x==0) fst=0;
	else fst=x-f%x;
	int i;
	for (i=fst;i<=l-f;i=i+x) jump[i]=max(jump[i],x-1);
}
void init(void) {
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	scanf("%d",&l);
	scanf("%d",&f);
}
void process(void) {
	int i;
	for (i=0;i<=l-f;i=i+1) jump[i]=1;
	for (i=1;i<=n;i=i+1)
		if (i==1 || a[i]>a[i-1]) count(a[i]);
	for (i=0;i<=l-f;i=i+1) {
		next[i]=i+jump[i];
		if (i>0) next[i]=max(next[i],next[i-1]);
	}		 
	int cur=0;
	int res=0;
	while (cur<l-f) {
		res++;
		cur=next[cur];
	}
	printf("%d",res);
}
int main(void) {
	init();
	process();
	return 0;
}