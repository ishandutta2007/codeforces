#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define b(x) (1ll<<(((x)-1)))

int i,j,k,k2,t,n,m;
ll a,c,tmp,tmp2,b[66];

void add(ll x){
	for(int i=63;i>=1;i--){
		if(x&b(i)){
			if(b[i]){x^=b[i];}
			else{b[i]=x;break;}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&a,&c);
		tmp^=a;add(a^c);
	}
	for(i=1;i<=63;i++){
		for(j=i+1;j<=63;j++){
			if(b[j]&b(i)){b[j]^=b[i];}
		}
	}
	for(i=63;i>=1;i--){
		if(b[i]){k++;}
		if(tmp&b(i)){tmp^=b[i];}
	}
	if(tmp){puts("1/1");}
	else{printf("%lld/%lld",b(k+1)-1,b(k+1));}
}