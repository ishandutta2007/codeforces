#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,a[1000010];
int main(){
	scanf("%d %d",&n,&m);
	int k=m/n,re=m%n;
	if(k==1){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;i++) a[i]=k;
	for(int i=1;i<=re;i++) a[i]=k+1;
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("\n1");
}