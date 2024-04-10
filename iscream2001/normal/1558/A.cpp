#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int INF=1e9+5;
const int N=110;
int n,m;
int vis[200005];
void init(){
	return;
}
void MAIN(){
	int a,b;
	scanf("%d%d",&a,&b);
	//cout<<a<<" "<<b<<endl;
	n=a+b;
	for(int i=0;i<=n;++i) vis[i]=0;
	m=n>>1;
	n=n-m;
	for(int i=0;i<=a;++i){
		if(i>n||a-i>m) continue;
		vis[a+n-i-i]=1;
	}
	swap(n,m);
	for(int i=0;i<=a;++i){
		if(i>n||a-i>m) continue;
		vis[a+n-i-i]=1;
	}
	int ans=0;
	for(int i=0;i<=a+b;++i){
		if(vis[i]) ++ans;
	}
	printf("%d\n",ans);
	for(int i=0;i<=a+b;++i){
		if(vis[i]) printf("%d ",i);
	}
	puts("");
	return;
	return;
} 

int main(){
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*

*/