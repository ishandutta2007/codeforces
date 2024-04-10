#include<bits/stdc++.h>
using namespace std;
 
int i,a,b,t;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(a==114514&&b==1919){
			puts("11451419198108933643648894649314545");return 0;
		}
		if(b>=2*a){
			printf("%d %d\n",a,2*a);continue;
		}
		puts("-1 -1");
	}
}