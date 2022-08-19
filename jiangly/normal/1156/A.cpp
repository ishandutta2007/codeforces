#include<bits/stdc++.h>
const int MAXN=100;
int n,ans;
int a[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;++i){
		if(a[i]+a[i+1]==5){
			puts("Infinite");
			return 0;
		}
	}
	for(int i=1;i<n;++i){
		if(a[i]==2||a[i+1]==2){
			ans+=3;
		}else{
			ans+=4;
		}
	}
	for(int i=1;i<n-1;++i){
		if(a[i]==3&&a[i+1]==1&&a[i+2]==2){
			--ans;
		}
	}
	puts("Finite");
	printf("%d\n",ans);
	return 0;
}