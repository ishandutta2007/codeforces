#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,c;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		if(c>a){printf("1 ");}
		else{printf("-1 ");}
		if(a*b>c){printf("%lld",b);}
		else{printf("-1 ");}
		puts("");
	}
}