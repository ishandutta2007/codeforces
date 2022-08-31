#include <cstdio>
#include <algorithm>

long long a[10];
void Do(long long x){
	printf("%I64d\n",x);
	fflush(stdout);
	int tem;
	scanf("%d",&tem);
	a[tem]+=x;
}
int main(){
	scanf("%I64d%I64d%I64d",&a[1],&a[2],&a[3]);
	printf("First\n");
	fflush(stdout);
	Do(10000000000ll);
	long long mx=0;
	for(int i=1;i<=3;i++)if(mx<a[i])mx=a[i];
	Do((mx*3ll)-a[1]-a[2]-a[3]);
	std::sort(a+1,a+3+1);
	Do(a[2]-a[1]);
	return 0;
}