#include "bits/stdc++.h"
#define MAXN 200009
#define INF 998244353
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const int LOG=19;
int lvl[MAXN],P[MAXN][LOG],in[MAXN],T,out[MAXN];
vector<int>adj[MAXN],val[MAXN],tmp;
vector<PII>G[MAXN];
bool cmp(int x,int y){
	return (in[x]<in[y]);
}
int LCA(int x,int y){
	if(lvl[x]<lvl[y])
		swap(x,y);
	for(int i=LOG-1;i>=0;i--)
		if(P[x][i] and lvl[P[x][i]]>=lvl[y])
			x=P[x][i];
	if(x==y)
		return x;
	for(int i=LOG-1;i>=0;i--)
		if(P[x][i] and P[x][i]!=P[y][i])
			x=P[x][i],y=P[y][i];
	return P[x][0];
}
void dfs(int nd,int pr){
	in[nd]=++T;
	for(auto to:adj[nd])
		if(to!=pr){
			lvl[to]=lvl[nd]+1;
			P[to][0]=nd;
			dfs(to,nd);
		}
	out[nd]=T;
}
bool ata(int x,int y){
	return (in[x]<=in[y] and out[y]<=out[x]);
}
int dis(int x,int y){
	return lvl[x]+lvl[y]-2*lvl[LCA(x,y)];
}
int sub[MAXN],imp[MAXN],S,ans,big_ans;
void dfs1(int nd){
	sub[nd]=imp[nd];
	for(auto to:G[nd]){
		dfs1(to.ff);
		sub[nd]+=sub[to.ff];
	}
}
int mod(ll x){
	return x%INF;
}
int f(int x){
	return mod(x*1LL*(x-1)/2);
}
void dfs2(int nd){
	for(auto to:G[nd]){
		dfs2(to.ff);
		//~ cout<<nd<<" "<<to.ff<<" "<<to.ss<<endl;
		int x=S-sub[to.ff];
		int y=sub[to.ff];
		ans=mod(ans+mod(to.ss*1LL*mod(x*1LL*f(y))));
		ans=mod(ans+mod(to.ss*1LL*mod(y*1LL*f(x))));
	}
}
const int N=2e5+5;
int lp[N];
int main(){
    //~ freopen("file.in", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=2;i<N;i++){
		if(lp[i])
			continue;
		for(int j=i;j<N;j+=i)
			if(!lp[j])
				lp[j]=i;
	}
    for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int last=-1;
		while(x>1){
			if(lp[x]!=last){
				val[lp[x]].pb(i);
				last=lp[x];
			}
			x/=lp[x];
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1);
	for(int j=1;j<LOG;j++)
		for(int i=1;i<=n;i++)
			if(P[i][j-1])
				P[i][j]=P[P[i][j-1]][j-1];
	stack<int>st;
	for(int x=2;x<N;x++){
		if(val[x].empty())
			continue;
		vector<int>&v=val[x];
		//~ debug(x)
		//~ for(int i=0;i<(int)v.size();i++)
			//~ cout<<v[i]<<" ";
		//~ cout<<endl;
		sort(all(v),cmp);
		for(int j=0;j+1<(int)v.size();j++){
			tmp.pb(LCA(v[j],v[j+1]));
			imp[v[j]]=1;
		}
		imp[v.back()]=1;
		for(int i=0;i<(int)tmp.size();i++)
			v.pb(tmp[i]);
		sort(all(v),cmp);
		v.erase(unique(all(v)),v.end());
		st.push(v[0]);
		for(int j=1;j<(int)v.size();j++){
			while(!st.empty() and !ata(st.top(),v[j]))
				st.pop();
			G[st.top()].pb(mp(v[j],lvl[v[j]]-lvl[st.top()]));
			st.push(v[j]);
		}
		while(!st.empty())st.pop();
		while(!tmp.empty())tmp.ppb();
		dfs1(v[0]);
		S=sub[v[0]];
		dfs2(v[0]);
		big_ans=mod(big_ans+ans);
		ans=0;
		for(int j=0;j<int(v.size());j++)
			G[v[j]].clear(),imp[v[j]]=0;
		//~ break;
	}
	printf("%d\n",big_ans);
	return 0;
}