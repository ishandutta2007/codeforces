#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,m,n,t;
ll sb1[200500],sb2[200500],tmp;

ll gcd(ll a,ll b){
	if(!b){return a;}
	return gcd(b,a%b);
}

int main(){
	t=1;
	while(t--){
		scanf("%d%d",&n,&m);
		
		if(n==1){
			scanf("%lld",&sb1[1]);
			for(i=1;i<=m;i++){
				scanf("%lld",&tmp);
				printf("%lld ",tmp+sb1[1]);
			}return 0;
		}
		
		for(i=1;i<=n;i++){
			scanf("%lld",&sb1[i]);
		}
		
		for(i=1;i<=m;i++){
			scanf("%lld",&sb2[i]);
		}
		for(i=2;i<=n;i++){
			sb1[i]-=sb1[1];
		}
		tmp=sb1[2];
		for(i=2;i<=n;i++){
			tmp=gcd(tmp,sb1[i]);
		}
		for(i=1;i<=m;i++){
			printf("%lld ",gcd(tmp+sb1[1]+sb2[i],sb1[1]+sb2[i]));
		}
	}
}