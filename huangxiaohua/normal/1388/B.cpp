#include<bits/stdc++.h>
using namespace std;

int i,t,n,k;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=n/4+1;
		if(n%4==0){k--;}
		for(i=1;i<=n-k;i++){printf("9");}
		for(i=1;i<=k;i++){printf("8");}
		puts("");
	}
}