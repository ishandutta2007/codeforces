#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll sb[1005000],l,r,sum,md,res;
int main(){
	srand(time(0));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&l);sum+=l;
	}
	l=1;r=2e12;
	while(l<=r){
		md=(l+r)>>1;
		if((md+md+n-1)*n/2>sum){r=md-1;}
		else{l=md+1;res=max(res,md);}
	}
	for(i=1;i<=n;i++){
		sb[i]=res-1+i;sum-=sb[i];
	}
	for(i=1;sum;i++){
		sb[i]++;sum--;
	}
	for(i=1;i<=n;i++){
		printf("%lld ",sb[i]);
	}
}