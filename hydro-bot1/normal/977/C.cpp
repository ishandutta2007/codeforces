// Hydro submission #62fdb29fe42c71bad9eed363@1660793503864
#include<bits/stdc++.h>

using namespace std;

int a[2000010],n,k;

int main(){
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a+1,a+1+n);
	if(k==0){
		if(a[1]==1) puts("-1");
		else puts("1");
		return 0;
	}
	if(a[k+1]==a[k]){
		puts("-1");
		return 0;
	}
	if(a[k]<=1000000000) printf("%d", a[k]);
	else puts("1000000000");
	return 0;
}