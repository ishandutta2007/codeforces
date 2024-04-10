#include <cstdio>
#include <algorithm>

int b,g,n;
int main(){
	scanf("%d%d%d",&b,&g,&n);
	int l=std::max(0,n-g),r=std::min(b,n);
	if(l>r)puts("0");
	printf("%d\n",r-l+1);
}