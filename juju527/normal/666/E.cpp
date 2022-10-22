#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=5e4+4,maxq=5e5+5;
int n,m;
char S[maxn],T[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct seg{
	int ls,rs;
	int mx,pos;
}t[200*maxm];
int siz;
int root[(maxn+maxm)<<1];
int newnode(int ls,int rs,int mx,int pos){
	int k=++siz;
	t[k].ls=ls;t[k].rs=rs;t[k].mx=mx;t[k].pos=pos;
	return k;
}
int copy(int x){
	return newnode(t[x].ls,t[x].rs,t[x].mx,t[x].pos);
}
void update(int k){
	int ls=t[k].ls,rs=t[k].rs;
	if(ls==0&&rs==0){t[k].mx=0;t[k].pos=m+1;return ;}
	if(!ls){t[k].mx=t[rs].mx;t[k].pos=t[rs].pos;return ;}
	if(!rs){t[k].mx=t[ls].mx;t[k].pos=t[ls].pos;return ;}
	t[k].mx=max(t[ls].mx,t[rs].mx);
	if(t[ls].mx==t[k].mx)t[k].pos=t[ls].pos;
	else t[k].pos=t[rs].pos;
	return ;
}
void modify(int &k,int l,int r,int x){
	if(!k)k=newnode(0,0,0,m+1);
	if(l==r){t[k].mx++;t[k].pos=x;return ;}
	int mid=l+((r-l)>>1);
	if(x<=mid)modify(t[k].ls,l,mid,x);
	else modify(t[k].rs,mid+1,r,x);
	update(k);
	return ;
}
int merge(int x,int y,int l,int r){
	if(x==0||y==0)return copy(x+y);
	if(l==r){int k=copy(x);t[k].mx+=t[y].mx;t[k].pos=l;return k;}
	int mid=l+((r-l)>>1);
	int k=copy(x);
	t[k].ls=merge(t[k].ls,t[y].ls,l,mid);
	t[k].rs=merge(t[k].rs,t[y].rs,mid+1,r);
	update(k);
	return k;
}
void query(int k,int l,int r,int x,int y,int &b,int &c){
	if(!k)return ;
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){
		if(b<t[k].mx)b=t[k].mx,c=t[k].pos;
		else if(t[k].mx&&b==t[k].mx)c=min(c,t[k].pos);
		return ;
	}
	int mid=l+((r-l)>>1);
	query(t[k].ls,l,mid,x,y,b,c);
	query(t[k].rs,mid+1,r,x,y,b,c);
	return ;
}
int cur;
int trie[maxn+maxm][26];
vector<int>b[maxn+maxm];
void ins(int id,char *s){
	int k=0,len=strlen(s+1);
	for(int i=1;i<=len;i++){
		int to=s[i]-'a';
		if(!trie[k][to])trie[k][to]=++cur;
		k=trie[k][to];
		if(id)b[k].push_back(id);
	}
	return ;
}
int tot=1;
int to[(maxn+maxm)<<1][26],len[(maxn+maxm)<<1],nxt[(maxn+maxm)<<1];
int extend(int id,int last,int c){
	int u=++tot,p=last;
	len[u]=len[p]+1;
	for(int i=0;i<b[id].size();i++)modify(root[u],1,m,b[id][i]);
	while(p&&to[p][c]==0){to[p][c]=u;p=nxt[p];}
	if(!p)nxt[u]=1;
	else{
		int d=to[p][c];
		if(len[d]==len[p]+1)nxt[u]=d;
		else{
			int v=++tot;
			for(int i=0;i<26;i++)to[v][i]=to[d][i];
			len[v]=len[p]+1;
			nxt[v]=nxt[d];nxt[d]=v;nxt[u]=v;
			while(p&&to[p][c]==d){to[p][c]=v;p=nxt[p];}
		}
	}
	return u;
}
int lst[(maxn+maxm)<<1];
queue<int>q;
void bfs(){
	q.push(0);lst[0]=1;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int tmp=trie[k][i];
			if(!tmp)continue;
			lst[tmp]=extend(tmp,lst[k],i);
			q.push(tmp);
		}
	}
	return ;
}
struct Edge{
	int to,nxt;
}e[(maxn+maxm)<<1];
int cnt;
int head[(maxn+maxm)<<1];
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
int f[(maxn+maxm)<<1][21];
void dfs(int x,int fa){
	f[x][0]=fa;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		dfs(tmp,x);
		root[x]=merge(root[x],root[tmp],1,m);
	}
	return ;
}
int lft[maxn];
int main(){
//    freopen("CF666E.in","r",stdin);
//    freopen("CF666E.out","w",stdout);
   	scanf("%s",S+1);n=strlen(S+1);
	ins(0,S);
	m=read();
	for(int i=1;i<=m;i++){
		scanf("%s",T+1);
		ins(i,T);
	}
	bfs();
	memset(head,-1,sizeof(head));
	for(int i=2;i<=tot;i++)add(nxt[i],i);
	dfs(1,0);
	int p=1;
	for(int i=1;i<=n;i++){
		p=to[p][S[i]-'a'];
		lft[i]=p;
	}
	int Q;
	Q=read();
	for(int i=1;i<=Q;i++){
		int l,r,pl,pr;
		l=read();r=read();pl=read();pr=read();
		p=lft[pr];
		for(int j=20;j>=0;j--)
			if(len[f[p][j]]>=pr-pl+1)
				p=f[p][j];
		int b=0,c=m+1;
		query(root[p],1,m,l,r,b,c);
		if(b==0)c=l;
		printf("%d %d\n",c,b);
	}
    return 0;
}