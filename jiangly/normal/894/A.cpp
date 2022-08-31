#include<bits/stdc++.h>
const int N=1e2+5;
int n,ans;
char a[N];
int sum_1[N],sum_2[N];
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;++i){
		sum_1[i]=sum_1[i-1]+(a[i]=='Q');
	}
	for(int i=n;i;--i){
		sum_2[i]=sum_2[i+1]+(a[i]=='Q');
	}
	for(int i=1;i<=n;++i){
		if(a[i]=='A'){
			ans+=sum_1[i-1]*sum_2[i+1];
		}
	}
	printf("%d\n",ans);
	return 0;
}