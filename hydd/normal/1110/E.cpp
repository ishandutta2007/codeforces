#include<bits/stdc++.h>
using namespace std;
int n,a[110000],b[110000],c[110000],d[110000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) c[i]=a[i]-a[i-1];
	sort(c+2,c+n+1);
	
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) d[i]=b[i]-b[i-1];
	sort(d+2,d+n+1);
	
	for (int i=1;i<=n;i++)
		if (c[i]!=d[i]){
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}