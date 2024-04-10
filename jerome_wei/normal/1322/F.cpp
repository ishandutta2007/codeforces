#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
typedef pair<int,int> pi;
vector<int> g[N],id[N];
int n,m;
struct UST{
	vector<int> fa,c;
	inline void init(int n){
		fa.resize(n+1);
		c.resize(n+1);
		for(int i=0;i<=n;i++)fa[i] = i;
	}
	inline int find(int x){
		if(fa[x]==x)return x;
		else{
			find(fa[x]); c[x] ^= c[fa[x]]; fa[x] = fa[fa[x]];
			return fa[x];
		}
	}
	inline void mrg(int x,int y){
		// cout << x << " " << y << "::::";
		find(x),find(y);
		if(fa[x]^fa[y]){
			// cout << fa[x] << " " << fa[y] << endl;
			c[fa[x]]=1^c[x]^c[y];
			fa[fa[x]]=fa[y];
		}else if(c[x]==c[y]){puts("-1");exit(0);/*no solution.*/}
		
		// for(int i=0;i<2;i++)cout << fa[i] << " " << c[i] << " | ";puts("");
	}
}us[N];

int p[N];//to calc merge
int p2[N];//to calc ifedge
int dep[N],anc[N][20];

inline void adde(int u,int v){g[u].push_back(v);id[u].push_back(-1);}
inline void dfs(int x,int pre){
	anc[x][0]=pre;dep[x] = dep[pre]+1;
	for(int i=1;i<=19;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	us[x].init(g[x].size());
	for(size_t i=0;i<g[x].size();i++){
		int v=g[x][i];if(v==pre)continue;
		dfs(v,x);
	}
}
vector<pi> opts[N];
inline void perform(int x,int y){
	if(x==y)return;
	if(dep[x]<dep[y])swap(x,y);
	int _x=x;
	p2[x]++,p2[y]++;
	for(int i=19;~i;i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x!=y){
		p[_x]++,p[y]++;
		for(int i=19;~i;i--){
			if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
		}p[x]--,p[y]--;
		opts[anc[x][0]].push_back(pi(x,y));
		p2[anc[x][0]]-=2;
	}else{
		x=_x;p[x]++;for(int i=19;~i;i--)if(dep[anc[x][i]]>dep[y])x=anc[x][i];p[x]--;
		p2[y]-=2;
	}
}
int K;
bool FLAG;
int f[N],temp_id[N];
vector<int> h[N][2];
inline void pref(int x,int pre){
	for(int j=0;j<2;j++)h[x][j].resize(g[x].size());
	for(size_t i=0;i<g[x].size();i++){
		int v=g[x][i];if(v==pre)continue;
		pref(v,x);p[x]+=p[v];p2[x]+=p2[v];
	}
	for(size_t i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(v==pre&&p2[x])id[x][i]=i;
		else if(p2[v])id[x][i]=i;
	}
	for(size_t i=0;i<g[x].size();i++){int v=g[x][i];temp_id[v]=id[x][i];}
	for(size_t i=0;i<g[x].size();i++){
		int v=g[x][i];if(v!=pre&&p[v]){
			// cout << x << ":" << v << " " << pre << endl;
			us[x].mrg(temp_id[v],temp_id[pre]);
		}
	}
	for(size_t i=0;i<opts[x].size();i++){
		int a=opts[x][i].first,b=opts[x][i].second;
		// cout << x << ":"<< opts[x][i].first << " " << opts[x][i].second << endl;
		us[x].mrg(temp_id[a],temp_id[b]);
	}
	for(size_t i=0;i<g[x].size();i++){
		if(id[x][i]!=-1){
			// cout << us[x].fa[id[x][i]] << "," << us[x].c[id[x][i]] << "|";
			us[x].find(id[x][i]);
			// cout << us[x].fa[id[x][i]] << "," << us[x].c[id[x][i]] << "|";
		}
	}
	// puts("");
}/* to make the union set */
int dir[N];
inline void Dp(int x,int pre){
	// cout << x << " " << pre << endl;
	f[x]=1;
	// vector<int> h[2]={vector<int>(g[x].size(),0),vector<int>(g[x].size(),0)};
	for(int i=0;i<(int)g[x].size();i++)h[x][0][i]=h[x][1][i]=0;
	int qwq[2]={0,0};
	int idd=-1,cidd=0;
	for(size_t i=0;i<g[x].size();i++){
		if(g[x][i]==pre){
			if(id[x][i]!=-1)idd=us[x].fa[id[x][i]],cidd=us[x].c[id[x][i]];
		}
	}
	for(size_t i=0;i<g[x].size();i++){
		int v=g[x][i];if(v==pre)continue;
		Dp(v,x);
		if(id[x][i]!=-1){
			// cout << x << " " << v << "!!" << endl;
			if(us[x].fa[id[x][i]]==idd){
				dir[v]=(us[x].c[id[x][i]]==cidd);
				// cout << id[x][i] << " " << us[x].c[id[x][i]] << " " << cidd << endl;
				// cout << dir[v] << endl;
				//1 : x is source 0 : x is towards (when direction to fa is x to fa)
				if(us[x].c[id[x][i]]!=cidd)qwq[0]=max(qwq[0],f[v]);
				else qwq[1]=max(qwq[1],f[v]);
			}
			else{
				h[x][us[x].c[id[x][i]]][us[x].fa[id[x][i]]]=max(h[x][us[x].c[id[x][i]]][us[x].fa[id[x][i]]],f[v]);
			}
		}
	}
	// cout << " consider " << x << " " << pre << ":: " << qwq[0] << " " << qwq[1] << endl;
	int qaq[2]={0,0};
	for(size_t i=0;i<g[x].size();i++){
		// cout << h[0][i] << " " << h[1][i] << endl;
		int a=min(h[x][0][i],h[x][1][i]), b=max(h[x][0][i],h[x][1][i]);
		qaq[0]=max(qaq[0],a);
		qaq[1]=max(qaq[1],b);
	}
	int type=0;
	if(max(qaq[0],qwq[0])+max(qwq[1],qaq[1])<K){
		f[x]=max(qaq[0],qwq[0])+1;
	}
	else{
		type=1;
		if(max(qaq[1],qwq[0])+max(qwq[1],qaq[0])<K)f[x]=max(qaq[1],qwq[0])+1;
		else FLAG=0,f[x]=1;
	}
	for(size_t i=0;i<g[x].size();i++){
		int v=g[x][i];if(v==pre)continue;
		if(id[x][i]!=-1){
			if(us[x].fa[id[x][i]]==idd)continue;
			int idx = us[x].fa[id[x][i]], c = us[x].c[id[x][i]];
			int cc = c^(h[x][0][idx]>h[x][1][idx])^type;
			dir[v]=cc;
		}
	}
	// cout << x << ":::" << f[x] << endl;
	// cout << "ret" << endl;
}

inline bool check(int k){
	// cout << "check" << ":" << k << endl;
	K=k,FLAG=1;
	Dp(1,0);
	// cout << FLAG << endl;
	return FLAG;
}

bool t[N];

int ans[N];

inline void getans(int x,int pre){
	ans[x]=t[x]?K+1-f[x]:f[x];
	for(size_t i=0;i<g[x].size();i++){
		if(g[x][i]==pre)continue;
		t[g[x][i]]=t[x]^dir[g[x][i]];
		getans(g[x][i],x);
	}
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		perform(u,v);
	}
	// cout << "??" << endl;
	pref(1,0);
	// cout << "??" << endl;
	int l=1,r=n;
	while(l<r){
		int mid = (l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout << l << endl;
	check(l);
	getans(1,0);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	puts("");return 0;
}

/* 
8 5
2 1
3 2
4 3
5 2
6 3
7 2
8 2
1 7
3 4
2 8
5 1
4 5
 */