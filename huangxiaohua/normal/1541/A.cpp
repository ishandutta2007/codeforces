#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,x,y;
double a[105],b[105],f1,f2;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(!(n&1)){
			for(i=1;i<=n;i++){
				printf("%d ",i+((i&1)?1:-1));
			}
		}
		else{
			printf("3 1 2 ");
			for(i=4;i<=n;i++){
				printf("%d ",i+((i&1)?-1:1));
			}
		}
		puts("");
	}
}