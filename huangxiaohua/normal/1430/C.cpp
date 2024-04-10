#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,mx,mn;
ll res;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==2){
			puts("2\n1 2");continue;
		}
		puts("2");
		printf("%d %d\n",n,n-2);
		printf("%d %d\n",n-1,n-1);
		for(i=n-3;i>=1;i--){
			printf("%d %d\n",i,i+2);
		}
	}
}