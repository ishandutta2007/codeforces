#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=40000;i++){
			if(i*i<=n){continue;}
			j=sqrt(i*i-n);
			if(j*j+n!=i*i){continue;}
			k=i/j;
			if(i/k!=j){continue;}
			printf("%d %d\n",i,k);goto aaa;
		}
		puts("-1");
		aaa:;
	}
}