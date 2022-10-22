#include<bits/stdc++.h>
using namespace std;
const int maxs=5e4+5,maxns=5e5+5e4+5;
int n;
char S[maxs],T[maxs];
int l[15],r[15];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int id=0;
int tot;
int t[maxns][26],pos[maxns];
vector<int>b[maxns];
void ins(int m){
	int x=0;
	for(int i=1;i<=m;i++){
		int to=T[i]-'a';
		if(!t[x][to])t[x][to]=++tot;
		if(id)b[x].push_back(id);
		x=t[x][to];
	}
	if(id)b[x].push_back(id);
	return ;
}
int nod=1;
int len[2*maxns],nxt[2*maxns];
int to[2*maxns][26];
int ed[2*maxns][11];
int extend(int lst,int c,int k){
	int p=lst,u=++nod;
	len[u]=len[p]+1;
	for(int i=0;i<b[k].size();i++)ed[u][b[k][i]]++;
//	cout<<"!"<<k<<" "<<u<<endl;
	while(p&&to[p][c]==0){to[p][c]=u;p=nxt[p];}
	if(!p)nxt[u]=1;
	else{
		int d=to[p][c];
		if(len[d]==len[p]+1)nxt[u]=d;
		else{
			int v=++nod;
			len[v]=len[p]+1;
			for(int i=0;i<26;i++)to[v][i]=to[d][i];
			nxt[v]=nxt[d];nxt[d]=v;nxt[u]=v;
			while(p&&to[p][c]==d){to[p][c]=v;p=nxt[p];}
		}
	}
	return u;
}
queue<int>q;
void bfs(){
	for(int i=0;i<26;i++)
		if(t[0][i]){
			pos[t[0][i]]=extend(1,i,t[0][i]);
			q.push(t[0][i]);
		}
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int tmp=t[k][i];
			if(!tmp)continue;
			pos[tmp]=extend(pos[k],i,tmp);
			q.push(tmp);
		}
	}
	return ;
}
struct node{
	int to,nxt;
}e[2*maxns];
int cnt;
int head[2*maxns];
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
void dfs(int x){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
//		cout<<"*"<<x<<" "<<tmp<<endl;
		dfs(tmp);
		for(int j=1;j<=n;j++)ed[x][j]+=ed[tmp][j];
	}
//	cout<<"*"<<x<<endl;
//	for(int j=1;j<=n;j++)cout<<ed[x][j]<<" ";cout<<endl;
//	cout<<x<<" "<<len[x]<<endl;
	return ;
}
bool tag[2*maxns];
int main(){
	scanf("%s",S+1);
	for(int i=1;i<=strlen(S+1);i++)T[i]=S[i];
	ins(strlen(S+1));
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",T+1);
		id=i;ins(strlen(T+1));
		l[i]=read();r[i]=read();
	}
	bfs();
	memset(head,-1,sizeof(head));
	for(int i=2;i<=nod;i++)add(nxt[i],i);
	dfs(1);
	int p=1,ans=0;
	for(int i=1;i<=strlen(S+1);i++){
		int c=S[i]-'a';
		p=to[p][c];
		int q=p;
		while(q&&!tag[q]){
			tag[q]=1;
			bool flag=0;
			for(int j=1;j<=n;j++)if(ed[q][j]<l[j]||ed[q][j]>r[j]){flag=1;break;}
			if(!flag)ans+=len[q]-len[nxt[q]];
			q=nxt[q];
		}
	}
	printf("%d\n",ans);
	return 0;
}