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
int vis[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=100;++i) vis[i]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<i;++j){
				vis[x[i]-x[j]]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=100;++i) if(vis[i]) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}