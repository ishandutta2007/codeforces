#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(ll a,ll b){a%=mod;int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/*math*/
const int N=1e6+5;
int hed[N],to[N],nxt[N],cnt;
int n;
typedef pair<int,int> edge;
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
edge e[N];int ecnt;
bool mark[N];

vector<int> sz;
int cur[N];

inline void dfs(int x,int pre){
	cur[x] =1;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
		if(mark[i]) {
			sz.push_back(cur[v]);
		}else cur[x] += cur[v];
	}
	if(pre==0)sz.push_back(cur[x]);
}
int pw[N];
int k,ans;
int main()
{
	cin >> n >> k;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
		int t;scanf("%d",&t);
		if(t==1){
			mark[cnt]=mark[cnt-1]=1;
		}
	}dfs(1,0);
	for(int i=0;i<=k;i++){
		pw[i]=qpow(n,i);
	}
	for(int i=0;i<sz.size();i++){
	//	cout<<sz[i]<<endl;
		int t=1;
		for(int j=1;j<k;j++){//i and i+1
			t=mul(t,sz[i]);
			ans =add(ans,mul(t,mul(n-sz[i],pw[k-j-1])));
		}
	}
	cout<<ans<<endl;
}