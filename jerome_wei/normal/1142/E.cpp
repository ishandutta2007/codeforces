#include<bits/stdc++.h>
using namespace std;

int query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int ans; scanf("%d",&ans);
	return ans;
}

const int N=2e5+5;
int hed[N],from[N],to[N],nxt[N],cnt;
int deg[N];
inline void adde(int u,int v){
	++cnt;from[cnt]=u,to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
int dfn[N],low[N],num,stk[N],top,col[N],cn;
vector<int> scc[N];
int n,m;
inline void tarjan(int x){
	dfn[x] = low[x] =++num;
	stk[++top] = x;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}else if(!col[v])low[x] = min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		++cn;
		while(stk[top]!=x){
			scc[cn].push_back(stk[top]);
			col[stk[top--]] = cn;
		}
		scc[cn].push_back(stk[top]);
		col[stk[top--]] = cn;
	}
}

queue<int> Non;
int S;
vector<int> toward[N];
inline void del(int x){
	int c=col[x];
	scc[c].pop_back();
	if(scc[c].size()){
		Non.push(scc[c][scc[c].size()-1]);
	}else{
		for(size_t i=0;i<toward[c].size();i++){
			int v=toward[c][i];
			deg[v]--;
			if(deg[v]==0)Non.push(scc[v][scc[v].size()-1]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=cnt;i++){
		if(col[from[i]]!=col[to[i]]){
			deg[col[to[i]]]++;
			toward[col[from[i]]].push_back(col[to[i]]);
		}
	}
	for(int i=1;i<=cn;i++)if(!deg[i]){
		Non.push(scc[i][scc[i].size()-1]);
	}
	S = Non.front();Non.pop();
	while(!Non.empty()){
		int t = Non.front(); Non.pop();
		int ret = query(S,t);
		if(ret==1){
			del(t);
		}else{
			del(S);
			S=t;
		}
	}
	cout << "! " << S << endl;
}