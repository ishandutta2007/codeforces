#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		int s=(k-1)/(n-1);
		printf("%d\n",s*n+k-s*(n-1));
	}
}