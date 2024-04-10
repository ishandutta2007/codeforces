#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,n,t;
ll a,sb,j;


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&sb);
			for(j=0;;j++){
				if((1<<j)<=sb&&(1<<(j+1))>=sb){
					printf("%lld ",1<<j);break;
				}
			}
		}puts("");
	}
}