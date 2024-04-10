#include<bits/stdc++.h>
const int N=1e2+5;
int n,ans;
char a[N];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<n;++i){
		ans+=(a[i]>a[i+1])-(a[i]<a[i+1]);
	}
	puts(ans>0?"YES":"NO");
	return 0;
}