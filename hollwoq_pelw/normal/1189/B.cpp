#include <bits/stdc++.h>
using namespace std;
int a[101010];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	if(a[n-1]>=a[n-2]+a[n-3])return puts("NO"),0;
	puts("YES");
	printf("%d %d %d ",a[n-2],a[n-1],a[n-3]);
	for(int i=n-3;i--;)printf("%d ",a[i]);puts("");
}