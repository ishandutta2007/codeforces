#include<bits/stdc++.h>
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int m,c;
		scanf("%d%d",&m,&c);
		ans+=(m>c)-(m<c);
	}
	if(ans>0){
		puts("Mishka");
	}else if(ans==0){
		puts("Friendship is magic!^^");
	}else{
		puts("Chris");
	}
	return 0;
}