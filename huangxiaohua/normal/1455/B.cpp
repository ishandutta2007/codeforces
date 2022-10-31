#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007

int i,j,k,n,t,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);tmp=0;
		for(i=1;;i++){
			tmp+=i;
			if(tmp==n){printf("%d\n",i);break;}
			if(tmp>n){
				if(tmp==(n+1)){
					printf("%d\n",i+1);break;
				}
				printf("%d\n",i);break;
			}
		}
	}
}