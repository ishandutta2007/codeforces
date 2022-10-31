#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,res,k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++){
			printf("a");
		}
		for(i=1;i<=n-k;i++){
			printf("%c",'a'+i%3);
		}
		puts("");
	}
	return 0;
}