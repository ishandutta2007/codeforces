#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const LL INF=1e18;
const LD eps=1e-18;
const int N=2e5+10;
const LL P=998244353;
const LD PI=acos(-1.0);
LL qpow(LL x,LL y){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
int n,m,Q;
int vis[N];
void MAIN(){
	int op,u,v,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		++vis[u];
		if(vis[u]==1) ++ans;
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&u,&v);
			if(u>v) swap(u,v);
			++vis[u];
			if(vis[u]==1) ++ans;
		}
		else if(op==2){
			scanf("%d%d",&u,&v);
			if(u>v) swap(u,v);
			--vis[u];
			if(vis[u]==0) --ans;
		}
		else{
			printf("%d\n",n-ans);
		}
	}
    return;
}

int main(){
    //init();
    int ttt=1;
	//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;
}