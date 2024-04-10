#include<bits/stdc++.h>
int n;
int cnt1,cnt2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		if(a==1){
			++cnt1;
		}else{
			++cnt2;
		}
	}
	if(!cnt1){
		for(int i=1;i<=n;++i){
			printf("2 ");
		}
	}else if(!cnt2){
		for(int i=1;i<=n;++i){
			printf("1 ");
		}
	}else{
		printf("2 1 ");
		for(int i=1;i<=cnt2-1;++i){
			printf("2 ");
		}
		for(int i=1;i<=cnt1-1;++i){
			printf("1 ");
		}
	}
	return 0;
}