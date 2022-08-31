#include<bits/stdc++.h>
int n,ans;
int main(){
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		ans|=x;
	}
	puts(ans?"HARD":"EASY");
	return 0;
}