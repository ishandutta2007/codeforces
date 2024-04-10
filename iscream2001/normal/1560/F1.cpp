#include<bits/stdc++.h>
#define LL long long
#define LD long double 
using namespace std;
const LL INF=1e18;
LL n;
int K;
int len;
int p[20];
int vis[20];
int check(){
	int re=0;
	for(int i=0;i<=9;++i){
		if(vis[i]>0) ++re;
	}
	return re;
}
void MAIN(){
	LL ans=INF,now;
	scanf("%lld%d",&n,&K);
	if(K==1){
		ans=INF;
		for(LL i=1;i<=9;++i){
			now=0;
			while(now<n){
				now=now*10+i;
			}
			ans=min(ans,now);
		}
		printf("%lld\n",ans);
		return;
	}
	now=1;
	while(now<n){
		now=now*10;
	}
	ans=min(ans,now);
	LL m=n;
	len=0;
	while(m>0){
		p[len]=m%10;
		m=m/10;
		++len;
	}
	for(int i=0;i<10;++i) vis[i]=0;
	LL las=0;
	int res;
	for(int j=len-1;j>=0;--j){
		for(LL w=p[j]+1,z;w<=9;++w){
			now=las*10+w;
			++vis[w];
			res=check();
			if(res>K) {
				--vis[w];
				continue;
			}
			if(res<K){
				z=0;
			}
			else {
				for(int k=9;k>=0;--k){
					if(vis[k]>0) z=k;
				}
			}
			for(int k=j-1;k>=0;--k){
				now=now*10+z;
			}
			ans=min(ans,now);
			--vis[w];
		}
		++vis[p[j]];
		las=las*10+p[j];
	}
	res=check();
	if(res<=K) ans=min(ans,las);
	printf("%lld\n",ans);
	return;
} 


int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*

*/