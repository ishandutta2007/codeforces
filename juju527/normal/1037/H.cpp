#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,Q,m;
int l,r;
char S[maxn],T[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct seg{
	int ls,rs,mx;
}t[80*maxn];
int cur=0;
int root[maxn<<1];
int newnode(int x,int ls,int rs){
	int k=++cur;
	t[k].ls=ls;t[k].rs=rs;
	t[k].mx=x;
	return k;
}
int copy(int x){
	return newnode(t[x].mx,t[x].ls,t[x].rs);
}
void modify(int &k,int l,int r,int x){
	if(!k)k=newnode(0,0,0);
	if(l==r){t[k].mx=x;return ;}
	int mid=l+((r-l)>>1);
	if(x<=mid){modify(t[k].ls,l,mid,x);t[k].mx=t[t[k].ls].mx;}
	else{modify(t[k].rs,mid+1,r,x);t[k].mx=t[t[k].rs].mx;}
	return ;
}
int merge(int x,int y,int l,int r){
	if(x==0||y==0)return copy(x+y);
	if(l==r){int k=copy(x);t[k].mx=max(t[k].mx,t[y].mx);return k;}
	int mid=l+((r-l)>>1);
	int k=copy(x);
	t[k].ls=merge(t[k].ls,t[y].ls,l,mid);
	t[k].rs=merge(t[k].rs,t[y].rs,mid+1,r);
	t[k].mx=max(t[t[k].ls].mx,t[t[k].rs].mx);
	return k;
}
int query(int k,int l,int r,int x,int y){
	if(!k)return 0;
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return t[k].mx;
	int mid=l+((r-l)>>1);
	return max(query(t[k].ls,l,mid,x,y),query(t[k].rs,mid+1,r,x,y));
}
int tot=1,last=1;
int to[maxn<<1][26],len[maxn<<1],nxt[maxn<<1];
void extend(int id,int c){
	int u=++tot,p=last;
	len[u]=len[p]+1;modify(root[u],1,n,id);
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
	last=u;
	return ;
}
struct Edge{
	int to,nxt;
}e[maxn<<1];
int cnt;
int head[maxn<<1];
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
void dfs(int x){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		dfs(tmp);
		root[x]=merge(root[x],root[tmp],1,n);
	}
	return ;
}
int a[maxn];
int solve(int pos,int x){
	if(pos==m+1){
		for(int i=0;i<26;i++){
			int tmp=to[x][i];
			if(!tmp)continue;
			a[pos]=i;
			if(query(root[tmp],1,n,1,r)-pos+1>=l)return pos;
		}
		return 0;
	}
	int c=T[pos]-'a';
	if(to[x][c]&&query(root[to[x][c]],1,n,1,r)-pos+1>=l){
		a[pos]=c;
		int t=solve(pos+1,to[x][c]);
		if(t)return t;
	}
	for(int i=c+1;i<26;i++){
		int tmp=to[x][i];
		if(!tmp)continue;
		a[pos]=i;
		if(query(root[tmp],1,n,1,r)-pos+1>=l)return pos;
	}
	return 0;
}
int main(){
//    freopen("CF1037H.in","r",stdin);
//    freopen("CF1037H.out","w",stdout);
   	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=1;i<=n;i++)extend(i,S[i]-'a');
	memset(head,-1,sizeof(head));
	for(int i=2;i<=tot;i++)add(nxt[i],i);
	dfs(1);
	Q=read();
	for(int i=1;i<=Q;i++){
		l=read();r=read();
		scanf("%s",T+1);
		m=strlen(T+1);
		int siz=solve(1,1);
		if(!siz)printf("-1\n");
		else{
			for(int j=1;j<=siz;j++)putchar(a[j]+'a');
			putchar('\n');
		}
	}
    return 0;
}