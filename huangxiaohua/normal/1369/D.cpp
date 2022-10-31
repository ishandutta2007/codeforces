#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;
 
ll tmp,n,t,sb[2000500][4],i;
 
 
int main(){
	sb[1][0]=1;
	for(i=2;i<=2000050;i++){
		sb[i][1]=sb[i-1][0]%M;
		sb[i][2]=(sb[i-1][2]+sb[i-1][1])%M;
		sb[i][0]=(sb[i-1][0]+sb[i-1][1]*2)%M;
		sb[i][3]=sb[i-2][0]*4%M;
		if(i>=3){sb[i][3]+=sb[i-3][3];
			sb[i][3]%=M;
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=2){puts("0");continue;
		}
		printf("%lld\n",sb[n][3]);
	}
}