
#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=3e5+10;
const LL INF=1e18;
void init(){
}

int n,K;
//LL fac[N],finv[N];
//LL C(LL x,LL y){
//	if(x<y) return 0;
//	return fac[x]*finv[y]%P*finv[x-y]%P; 
//}
char s[N];
int a[N],b[N];
vector<LL> V[30];
int tp[30];

LL t[N];
LL vis[30];
void add(int x,LL w){
	while(x<=n){
		t[x]+=w;
		x+=x&-x;
	} 
}
LL ask(int x){
	LL re=0;
	while(x>0){
		re+=t[x];
		x-=x&-x;
	}
	return re;
}
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) a[i]=s[i]-'a';
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) b[i]=s[i]-'a';
	for(int i=0;i<26;++i) {
		V[i].clear();
	}
	for(int i=0;i<=n;++i) t[i]=0;
	for(int i=n;i>=1;--i){
		V[a[i]].push_back((LL)i);
	}
	for(int j=0;j<26;++j){
		tp[j]=V[j].size();
	}
	int id;
	LL www;
	
	LL ans=INF,now=0;
	int x;
	for(int i=1;i<=n;++i){
		www=INF;id=0;
		for(int j=0;j<b[i];++j){
			vis[j]=INF;
			if(tp[j]==0){
				continue;
			}
			vis[j]=V[j][tp[j]-1]+ask(V[j][tp[j]-1]);
			if(vis[j]<www){
				www=vis[j];
				id=j;
			}
		}
		if(www<=n){
			ans=min(ans,now+www-(LL)i);
		}
		www=INF;id=0;
		for(int j=b[i];j<=b[i];++j){
			vis[j]=INF;
			if(tp[j]==0){
				continue;
			}
			vis[j]=V[j][tp[j]-1]+ask(V[j][tp[j]-1]);
			if(vis[j]<www){
				www=vis[j];
				id=j;
			}
		}
		if(www<=n){
			now+=www-i;
			x=V[id][tp[id]-1];
			--tp[id];
			add(1,(LL)1);
			add(x,(LL)(-1));
		}
		else{
			break;
		}
	}
	if(ans==INF) puts("-1");
	else printf("%lld\n",ans);
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}