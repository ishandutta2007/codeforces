#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
const int inv2=qpow(2,mod-2);
/* math */
const int N = 1e6+5;
int n;
int hed[N],cnt,to[N],nxt[N];
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
int f[N][2];
int ans=0;
inline void dfs(int x,int pre){
	int way0=1;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
		way0 = mul(way0,add(mul(inv2,f[v][0]),f[v][1]));
	}
	int way1 = sub(1,way0);
	
	f[x][0] = way0;
	f[x][1] = way1;
	ans= add(ans, way1);
}

int main()
{
	cin >> n;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	dfs(1,0);
	cout << mul(ans, qpow(2,n)) << endl;
}