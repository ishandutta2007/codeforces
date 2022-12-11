#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&k);
		if(n<k) printf("1 ");
		else printf("-1 ");
		if(1ll*m*n>k) printf("%d\n",m);
		else printf("-1\n");
	}
}