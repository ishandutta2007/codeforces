#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,t,m,n,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1;i<k+k-n;i++){
			printf("%d ",i);
		}
		for(i=k;i>=k+k-n;i--){
			printf("%d ",i);
		}puts("");
	}
}