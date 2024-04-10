#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)

int i,j,n,m,k,t,a[105][105],it;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==2){puts("-1");continue;}
		it=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d ",it);
				it+=2;
				if(it>n*n){it=2;}
			}puts("");
		}
	}
}