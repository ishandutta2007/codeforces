#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 13005000
int i,j,k,n,m,t,dep[400500],fa[400500],id[400500][28],it;
vector<int> v[400500],v1[N];
void dfs(int x,int f){
	fa[x]=f;dep[x]=dep[f]+1;
	for(auto i:v[x])if(i!=f)dfs(i,x);
}
void fuck(int a,int pos,int c){
	c-='a'-1;int k;
	for(int i=1;i<=26;i++){
		int &k=id[pos][i];
		if(!k)k=++it;
		if(i==c)v1[a].push_back(k);
		else v1[k].push_back(a^1);
	}
}
int top,it2,tot;
int dfn[N],sta[N],low[N],g[N];
bool insta[N];
void dfs2(int x){
	sta[++top]=x;insta[x]=1;
	dfn[x]=low[x]=++it2;
	for(auto i:v1[x]){
		if(!dfn[i]){
			dfs2(i);low[x]=min(low[x],low[i]);
		}
		else if(insta[i])low[x]=min(low[x],dfn[i]);
	}
	if(dfn[x]==low[x]){
		tot++;do{g[sta[top]]=tot;insta[sta[top]]=0;}while(sta[top--]!=x);
	}
}
string s0[800500],res;
vector<int> len[800500];
bool vis[13000500];
void fuck2(int id,int n,int rev){
	if(rev)reverse(s0[i].begin(),s0[i].end());
	for(int i=0;i<n;i++)res[len[id][i]]=s0[id][i];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);v[k].push_back(j);
	}
	dfs(1,0);
	it=m+m+5;
	for(i=1;i<=m;i++){
		string s;int x,y;
		cin>>x>>y>>s;
		s0[i]=s;
		vector<int> vx,vy;
		while(x!=y){
			if(dep[x]>=dep[y])vx.push_back(x),x=fa[x];
			else vy.push_back(y),y=fa[y];
		}
		vx.push_back(x);
		reverse(vy.begin(),vy.end());
		vx.insert(vx.end(),vy.begin(),vy.end());
		len[i]=vx;
		int n1=s.size();
		for(j=0;j<n1;j++)fuck(i*2,vx[j],s[j]);
		reverse(vx.begin(),vx.end());
		for(j=0;j<n1;j++)fuck(i*2+1,vx[j],s[j]);
	}
	for(i=1;i<=it;i++)if(!dfn[i])dfs2(i);
	for(i=1;i<=m;i++)if(g[i*2]==g[i*2+1]){cout<<"NO";return 0;}
	res=string(n+1,'z');
	for(i=1;i<=m;i++){
		int x,y;
		x=g[i*2];y=g[i*2+1];
		if(vis[x]){fuck2(i,len[i].size(),0);continue;}
		if(vis[y]){fuck2(i,len[i].size(),1);continue;}
		if(x<y){vis[x]=1;fuck2(i,len[i].size(),0);}
		else{vis[y]=1;fuck2(i,len[i].size(),1);}
	}
	cout<<"YES\n"<<res.substr(1);
}