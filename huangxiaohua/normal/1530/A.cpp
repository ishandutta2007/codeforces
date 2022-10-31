#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=0;
		while(n){
			k=max(k,(n%10));
			n/=10;
		}
		printf("%d\n",k);
	}
}