#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,n,a,t,m,k;
ll res,b[200500],pre,jc[105],inv[105];

ll ksm(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1){res=res*a%M;}
		a=a*a%M;
		p>>=1;
	}
	return res;
}

ll C(ll a,ll b){
	int i;
	ll res=1;
	if(b>a){return 0;}
	for(i=1;i<=b;i++){
		res=(res*(a+1-i))%M;
	}
	return res*inv[b]%M;
}


int main(){
	scanf("%d",&t);
	jc[0]=1;
	for(i=1;i<=105;i++){
		jc[i]=jc[i-1]*i%M;
		inv[i]=ksm(jc[i],M-2);
	}
	//printf("%lld",C(5,2));
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i++){
			b[i]=0;
		}
		
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			b[a]++;
		}
		
		pre=0;res=0;
		
		for(i=1;i<=n;i++){
			if(i>(k+1)){pre-=b[i-k-1];}
			
			res=((res+C(pre+b[i],m)-C(pre,m))%M+M)%M;
			
			pre+=b[i];
		}
		
		printf("%lld\n",res);
	}
}