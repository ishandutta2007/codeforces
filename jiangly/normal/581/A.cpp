#include<cstdio>
#include<algorithm>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	printf("%d %d\n",std::min(a,b),abs(a-b)>>1);
	return 0;
}