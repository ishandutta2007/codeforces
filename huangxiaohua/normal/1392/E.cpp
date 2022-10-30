#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define b(x) (1ll<<((x)-1))
int i,j,k,n,m,t;
ll sb[66][66],x;
int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&n);
	for(i=1;i<=n;i+=2){
		for(j=1;j<=n;j++){
			sb[i][j]=b(i+j-2);
		}
	}
	sb[1][1]=sb[n][n]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%lld ",sb[i][j]);
		}puts("");
	}
	fflush(stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&x);
		i=1;j=1;
		while(i!=n||j!=n){
			printf("%d %d\n",i,j);
			if(j==n){i++;continue;}
			if(i==n){j++;continue;}
			if(sb[i+1][j]){
				if(sb[i+1][j]&x){i++;}
				else{j++;}continue;
			}
			if(sb[i][j+1]){
				if(sb[i][j+1]&x){j++;}
				else{i++;}continue;
			}
		}
		printf("%d %d\n",n,n);
		fflush(stdout);
	}
}