#include<bits/stdc++.h>
int a,b,ans;
int main(){
	scanf("%d%d",&a,&b);
	while(a<=b){
		++ans;
		a*=3;
		b*=2;
	}
	printf("%d\n",ans);
	return 0;
}