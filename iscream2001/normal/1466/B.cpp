#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const LL P=998244353;
LL gcd(LL a,LL b) {
    return b?gcd(b,a%b):a;
}
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
int n;
int x[N];
int vis[N],b[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n+n+10;++i) {
			vis[i]=0;
			b[i]=0;
		}
		for(int i=1;i<=n;++i){
			scanf("%d",&x[i]);
			vis[x[i]]++;
		}
		int ans=0;
		for(int i=1;i<=n+n+10;++i){
			if(b[i]||vis[i]){
				++ans;
			}
			if(b[i]){
				if(vis[i]){
					b[i+1]=vis[i];
				}
			}
			else{
				if(vis[i]>1){
					b[i+1]=vis[i]-1;
				}
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}