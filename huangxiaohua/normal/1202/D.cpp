#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,sb2;


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sb=0;
		for(i=1;;i++){
			if((i*i-i)/2<=n&&((i+1)*(i+1)-i-1)/2>n){sb=i;break;}
		}
		n-=(sb*sb-sb)/2;
		
		printf("133");
		for(i=1;i<=n;i++){
			printf("7");
		}
		for(i=3;i<=sb;i++){
			printf("3");
		}
		printf("7");
		puts("");
	}
}