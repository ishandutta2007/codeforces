#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1ll<<((x)-1))
int i,j,k,n,m,t,it;
ll p[200500],b[66],sb,res[66],f[40][400500],b2[66],tmp[66],no[66];

int main() {
	p[0]=1;for(i=1;i<=200000;i++){p[i]=p[i-1]*2%M;}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&sb);
		for(j=m;j>=1;j--){
			if(sb&b(j)){
				if(b[j]){sb^=b[j];}
				else{b[j]=sb;break;}
			}
		}
	}
	for(i=1;i<=m;i++){
		for(j=i+1;j<=m;j++){
			if(b[j]&b(i)){b[j]^=b[i];}
		}
		if(b[i]){tmp[++t]=b[i];no[i]=1;}
	}
	memcpy(b,tmp,sizeof(tmp));
	
	if(t<=18){
		for(i=0;i<b(t+1);i++){
			sb=0;
			for(j=1;j<=t;j++){
				if(i&b(j)){sb^=b[j];}
			}
			res[__builtin_popcountll(sb)]++;
		}
	}
	else{
		for(i=1;i<=m;i++){
			if(no[i]){continue;}
			sb=0;
			for(j=1;j<=t;j++){
				if(b[j]&b(i)){sb=1;}
			}
			if(!sb){continue;}
			it++;
			for(j=1;j<=t;j++){
				if(b[j]&b(i)){b2[j]|=b(it);}
			}
			aaa:;
		}
		f[0][0]=1;
		for(i=1;i<=t;i++){
			for(j=t;j>=1;j--){
				for(k=0;k<b(it+1);k++){
					f[j][k]+=f[j-1][k^b2[i]];
					f[j][k]%=M;
				}
			}
		}
		for(i=0;i<=t;i++){
			for(j=0;j<b(it+1);j++){
				res[i+__builtin_popcountll(j)]+=f[i][j];
			}
		}
	}
	
	for(i=0;i<=m;i++){
		printf("%lld ",res[i]*p[n-t]%M);
	}
}