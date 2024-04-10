#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		for(j=1;j<=t;j++){
			if((i*j)>t&&!(i%j)&&(i/j)<t){
				printf("%d %d",i,j);return 0;
			}
		}
	}
	puts("-1");
}