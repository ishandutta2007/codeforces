#include<bits/stdc++.h>
using namespace std;
const int N = 3010;


struct edge{
	int x,y,w;
	edge(int x=0,int y=0,int w=0):x(x),y(y),w(w){}
	bool operator < (const edge b)const{
		return w < b.w;
	}
};
vector<edge> e;

int a[1510][1510];
int n;

int par[N],sz[N],s[N];
inline int find(int x){
	return par[x]==x?par[x]:par[x] = find(par[x]);
}
int ch[N][2];
int node;
int M[N];
inline void adde(int u,int v){
	u = find(u), v = find(v);
	if(u==v){
		sz[u]--;
		if(!sz[u])M[u] = 1;
		// cout << u << "!" << endl;
	}else{
		par[u] = par[v] = ++node;
		sz[node] = sz[u] + sz[v] + s[u]*s[v] - 1;
		if(!sz[node])M[node] = 1;
		ch[node][0] = u, ch[node][1] = v;
		s[node] = s[u] + s[v];
		// cout << node << ":" << ch[node][0] << " " << ch[node][1] << endl;
	}
}
int f[N][1510];
int _sz[N];
const int mod = 998244353;
inline void dp(int x){
	if(x<=n){
		f[x][1] = 1;
		_sz[x] = 1;
	}else{
		dp(ch[x][0]);
		dp(ch[x][1]);
		_sz[x] = _sz[ch[x][0]] + _sz[ch[x][1]];
		for(int i=1;i<=_sz[ch[x][0]];i++)for(int j=1;j<=_sz[ch[x][1]];j++){
			f[x][i+j] += 1ll * f[ch[x][0]][i] * f[ch[x][1]][j]%mod;
			if(f[x][i+j]>=mod)f[x][i+j]-=mod;
		}
		if(M[x])f[x][1] = 1;
	}
	return;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	node = n;
	for(int i=1;i<=n;i++)sz[i] = 0, s[i] = 1, par[i] = i, M[i] = 1;
	for(int i=n+1;i<=n*2;i++)par[i] = i;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		e.push_back(edge(i,j,a[i][j]));
	}
	sort(e.begin(), e.end());
	for(auto p:e){
		adde(p.x,p.y);
	}
	dp(node);
	for(int i=1;i<=n;i++)printf("%d ",f[node][i]);
}