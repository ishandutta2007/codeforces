#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			printf("%d ",4*n+2-i*2);
		}puts("");
	}
}