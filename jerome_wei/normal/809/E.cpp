#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
int n;
const int N=4e5+5;
int phi[N],mu[N],pcnt,prime[N],v[N];
vector<int> divisor[N];
inline void init(int n){
	phi[1]=mu[1]=1;
	for(int i=2;i<=n;i++) {
		if(!v[i]) {prime[++pcnt]=i;phi[i]=i-1;mu[i]=mod-1;}
		for(int j=1;j<=pcnt;j++) {
			int k=i*prime[j]; 
			if(k>n) break;
			v[k]=1;
			if(i%prime[j]){
				phi[k]=phi[i]*(prime[j]-1);
				mu[k]=mod-mu[i];
			} else {
				phi[k]=phi[i]*prime[j];
				mu[k]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i) divisor[j].push_back(i);
}

int hed[N],to[N],nxt[N],cnt,dep[N];
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
int a[N];
bool vis[N];
int S,root,mxsz=0x3f3f3f3f,sz[N];

inline void getroot(int x,int pre){
	sz[x]=1;
	int Mxsz=0;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre || vis[v])continue;
		getroot(v,x);
		sz[x]+=sz[v];Mxsz=max(Mxsz,sz[v]);
	}Mxsz=max(Mxsz,S-sz[x]);
	if(Mxsz<mxsz)mxsz=Mxsz,root=x;
}
int sigmaphi[N],sigmaphi_dis[N];
int Final[N];
void updateS(int x,int pre){
	sz[x]=1;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre || vis[v])continue;
		dep[v]=1+dep[x];
		updateS(v,x);
		sz[x]+=sz[v];
	}
}

inline void add_on(int x,int dep){
	for(size_t i=0;i<divisor[x].size();i++){
		int j=divisor[x][i];
//		cout<<"<"<<root<<">"<<j<<" : "<<Final[j]<<" < ";
		Final[j] = add(Final[j], mul(phi[x], mul(dep, sigmaphi[j])));
		Final[j] = add(Final[j], mul(phi[x], sigmaphi_dis[j]));
//		cout<<x<<" "<<dep<<" .> "<<Final[j]<<endl;
	}
}

inline void insert(int x,int dep,int tpe){
//	if(tpe==1)cout<<root<<"::"<<x<<" "<<dep<<endl;
	for(size_t i=0;i<divisor[x].size();i++){
		int j=divisor[x][i];
		sigmaphi[j] = add(sigmaphi[j], mul(tpe, phi[x]));
		sigmaphi_dis[j] = add(sigmaphi_dis[j], mul(tpe, mul(phi[x], dep)));
	}
}

void upd(int x,int pre){
	add_on(a[x],dep[x]);
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(vis[v]||v==pre)continue;
		upd(v,x);
	}
}
inline void updata(int x,int pre,int tpe){
	insert(a[x],dep[x],tpe);
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre||vis[v])continue;
		updata(v,x,tpe);
	}
}


inline void Divide(int x){
	dep[x]=0,updateS(x,0);
	insert(a[x],0,1);
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(vis[v])continue;
		upd(v,x);
		updata(v,x,1);
	}
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(vis[v])continue;
		updata(v,x,sub(mod,1));
	}
	insert(a[x],0,sub(mod,1));
//	for(int i=1;i<=n;i++){
//		cout<<Final[i]<<" ";
//	}puts("");
	vis[x]=1;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(vis[v])continue;
		S=sz[v],mxsz=0x3f3f3f3f,sz[x]=1;
		getroot(v,0);
		Divide(root);
	}
}


int main()
{
	cin >> n;
	init(n);
//	for(int i=1;i<=n;i++)cout<<phi[i]<<" ";
//	puts("");
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	S=n,root=1;
	getroot(1,0);
	Divide(root);
	int ans=0;
	for(int i=1;i<=n;i++){
		int ret=0;
		int T=mul(i, qpow(phi[i], mod-2));
		for(int j=i;j<=n;j+=i){
			ret=add(ret,mul(mu[j/i],Final[j]));
		}
		ans=add(ans, mul(ret, T));
	}
//	cout << ans << endl;
	int Way = mul(qpow(2,mod-2),mul(n,n-1));
	cout << mul(qpow(Way, mod-2), ans) << endl;
}
/*
6
6 5 1 2 3 4
6 1
5 1
6 3
6 4
1 2

*/