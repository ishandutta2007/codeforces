#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxk=1e5+5,maxl=1e6+5;
struct Edge{
	int to,nxt;
}e[maxl];
int cnt;
int head[maxl];
string s[maxk];
int ed[maxk];
int tot;
int t[maxl][26],tag[maxl],fail[maxl];
int dfsnum=0;
int dfn[maxl],son[maxl];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void ins(int id){
	int k=0;
	for(int i=0;i<s[id].size();i++){
		int to=s[id][i]-'a';
		if(!t[k][to])t[k][to]=++tot;
		k=t[k][to];
	}
	tag[k]++;
	ed[id]=k;
	return ;
}
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
queue<int>q;
void pre(){
	for(int i=0;i<26;i++)
		if(t[0][i])
			q.push(t[0][i]);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		add(fail[k],k);
		for(int i=0;i<26;i++){
			if(t[k][i]){
				fail[t[k][i]]=t[fail[k]][i];
				q.push(t[k][i]);
			}
			else
				t[k][i]=t[fail[k]][i];
		}
	}
	return ;
}
int sum[maxl];
int lowbit(int x){
	return x&-x;
}
void update(int x,int val){
	while(x<=tot+1){
		sum[x]+=val;
		x+=lowbit(x);
	}
	return ;
}
int query(int x){
	int ans=0;
	while(x){
		ans+=sum[x];
		x-=lowbit(x);
	}
	return ans;
}
void dfs(int x,int fa){
	dfn[x]=++dfsnum;
	son[x]=1;
	tag[x]+=tag[fa];
	update(dfn[x],tag[x]);
	update(dfn[x]+1,-tag[x]);
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
		son[x]+=son[tmp];
	}
	return ;
}
int query(string s){
	int k=0,ans=0;
	for(int i=0;i<s.size();i++){
		int to=s[i]-'a';
		k=t[k][to];
		ans+=query(dfn[k]);
	}
	return ans;
}
int main(){
//    freopen("CF163Ee-Government.in","r",stdin);
//    freopen("CF163Ee-Government.out","w",stdout);
   	int n,k;
	n=read();k=read();
	for(int i=1;i<=k;i++){
		cin>>s[i];
		ins(i);
	}
	memset(head,-1,sizeof(head));
	pre();
	dfs(0,0);
	for(int i=1;i<=n;i++){
		char opt;
		string s;
		int x,val=0;
		cin>>opt;
		if(opt=='?'){
			cin>>s;
			printf("%d\n",query(s));
		}
		else{
			x=read();
			int cur=query(dfn[ed[x]])-query(dfn[fail[ed[x]]]);
			if(opt=='+'){
				val=1;
				if(cur)val=0;
			}
			else{
				val=-1;
				if(!cur)val=0;
			}
		}
		if(val!=0){
			update(dfn[ed[x]],val);
			update(dfn[ed[x]]+son[ed[x]],-val);
		}
	}
    return 0;
}