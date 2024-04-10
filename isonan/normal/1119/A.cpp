#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int c[1000001],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
	}
	int lim=0;
	for(int i=1;i<=n;i++)if(c[i]==c[1])lim++;else break;
	int r=0;
	for(int i=n;i;--i)if(c[i]==c[n])r++;else break;
	if(c[1]!=c[n])printf("%d\n",n-1);
	else printf("%d\n",max(n-lim-1,n-r-1));
}