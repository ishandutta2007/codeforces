#include <bits/stdc++.h>
#define ope operator
#define re register
#define il inline
using namespace std;
int T,n,m,k,q,p[1010],cnt=0,st[1010];
bool isnt_prime[1010];
int query(long long x){
	printf("? %lld\n",x);
	fflush(stdout);
	int y;scanf("%d",&y);return y;
}
void solve(){
	int t=0;
	long long ans=1;
	for(int ttt=0,l=1,r=1;ttt<17;ttt++){
		long long x=1;
		for(;x<=1e18/p[r];r++) x*=p[r];
		x=query(x);
		for(;l<r;++l) if(x%p[l]==0) st[++t]=p[l];
		
	}
	for(int i=1;i<=t;i+=2){
		long long x=1;
		for(int j=0;i+j<=t&&j<=1;j++){
			int y=1;
			while(y<=1e9/st[i+j]) y*=st[i+j];
			x*=y;
		}
		x=query(x);
		for(int j=0;i+j<=t&&j<=1;j++){
			int y=0;
			while(x%st[i+j]==0) y++,x/=st[i+j];
			ans*=(y+1);
		}
	}
	printf("! %lld\n",max(ans+7,ans*2));fflush(stdout);
}
int main(){
	for(int i=2;i<=1000;i++){
		if(!isnt_prime[i]){
			p[++cnt]=i;
			for(int j=i+i;j<=1000;j+=i) isnt_prime[j]=true;
		}
	}
	scanf("%d",&T);
	while(T--) solve();
}