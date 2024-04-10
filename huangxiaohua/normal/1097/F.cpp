#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,m,t,prim[7777],mu[7777],vis[7777],cnt;

bitset<7005> sb[7005],u[7005],f[100500];

int main(){
	ios::sync_with_stdio(0);
	mu[1]=1;
	for(i=2;i<=7000;i++){
		if(!vis[i]) prim[++ cnt] = i, mu[i] = -1;
		for(j = 1; j <= cnt && prim[j] * i <= 7000; ++ j) {
			vis[i * prim[j]] = 1;
			if(i % prim[j] == 0) break;
			mu[i * prim[j]] = -mu[i];
		}
	}
	for(i=1;i<=7000;i++){
		for(j=i;j<=7000;j+=i){
			sb[j][i]=1;
			u[i][j]=(mu[j/i]!=0);
		}
	}
	scanf("%*d%d",&t);
	while(t--){
		scanf("%d",&k);
		if(k==1){
			scanf("%d%d",&j,&k);
			f[j]=sb[k];
			continue;
		}
		if(k==2){
			scanf("%d%d%d",&i,&j,&k);
			f[i]=(f[j]^f[k]);
			continue;
		}
		if(k==3){
			scanf("%d%d%d",&i,&j,&k);
			f[i]=(f[j]&f[k]);
			continue;
		}
		scanf("%d%d",&i,&j);
		putchar('0'+((f[i]&u[j]).count()&1));
	}
}