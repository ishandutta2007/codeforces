#include<bits/stdc++.h>
const int N=1e2+5;
int n;
int a[N],b[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		b[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		printf("%d ",b[i]);
	}
	return 0;
}