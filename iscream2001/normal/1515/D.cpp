#include<bits/stdc++.h>

using namespace std;
#define LL long long
const int N=3e5+10;
const LL INF=1e18;
const LL P=998244353;
LL add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
int n,L,R;
int a[N],b[N];
void MAIN(){
	scanf("%d%d%d",&n,&L,&R);
	for(int i=1;i<=n;++i){
		a[i]=b[i]=0;
	}
	int u;
	for(int i=1;i<=L;++i){
		scanf("%d",&u);
		++a[u];
	}
	for(int i=1;i<=R;++i){
		scanf("%d",&u);
		++b[u];
	}
	for(int i=1;i<=n;++i){
		u=min(a[i],b[i]);
		a[i]-=u;b[i]-=u;
	}
	if(L>R){
		swap(L,R);
		for(int i=1;i<=n;++i) swap(a[i],b[i]);
	}
	int t=(R-L)/2;
	int ans=t;
	for(int i=1;i<=n;++i){
		while(b[i]>=2&&t>0){
			b[i]-=2;
			t--;
		}
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=a[i]+b[i];
	}
	ans+=sum/2;
	printf("%d\n",ans);
	return;
}

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}