#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=401000;
char s[maxn];
int n,m,npos[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch2=ch;
	while(!isdigit(ch))ch2=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch2=='-'?-res:res;
}
struct Segment_Tree{
	int rt[maxn],verx;
	int son[2][maxn<<5];
	void modify(int &p,int pos,int l,int r){
		p=++verx;
		if(l==r)return;
		if(pos<=mid)modify(son[0][p],pos,l,mid);
		else modify(son[1][p],pos,mid+1,r);
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y||l==r)return x|y;
		int p=++verx;
		son[0][p]=merge(son[0][x],son[0][y],l,mid);
		son[1][p]=merge(son[1][x],son[1][y],mid+1,r);
		return p;
	}
	bool query(int p,int lr,int rr,int l,int r){
		if(lr>r||l>rr||!p)return false;
		if(lr<=l&&r<=rr)return true;
		if(lr<=mid&&query(son[0][p],lr,rr,l,mid))return true;
		if(rr>mid&&query(son[1][p],lr,rr,mid+1,r))return true;
		return false;
	}
}Q;
struct SAM{
	int ver,last;
	int len[maxn],nxt[26][maxn],link[maxn];
	vector<int> v[maxn];
	void reset(){
		ver=last=1;
		len[1]=0;link[1]=0;
	}
	void insert(int c){
		int cur=++ver;
		len[cur]=len[last]+1;
		Q.modify(Q.rt[cur],len[cur],1,n);
		int p=last;
		while(p&&!nxt[c][p]){
			nxt[c][p]=cur;
			p=link[p];
		}
		if(!p)link[cur]=1;
		else{
			int q=nxt[c][p];
			if(len[q]==len[p]+1)link[cur]=q;
			else{
				int clone=++ver;
				len[clone]=len[p]+1;
				for(register int i=0;i<26;++i)
					nxt[i][clone]=nxt[i][q];
				link[clone]=link[q];
				while(p&&nxt[c][p]==q){
					nxt[c][p]=clone;
					p=link[p];
				}
				link[q]=link[cur]=clone;
			}
		}
		last=cur;
	}
	void build(){
		for(register int i=2;i<=ver;++i)
			v[link[i]].push_back(i);
	}
	void dfs(int p){
		for(register int i=0;i<v[p].size();++i){
			dfs(v[p][i]);
			Q.rt[p]=Q.merge(Q.rt[p],Q.rt[v[p][i]],1,n);
		}
	}
	void query(){
		int l,r,now=1,lim;
		l=read();r=read();
		scanf("%s",s+1);
		m=strlen(s+1);
		for(lim=1;;++lim){
			npos[lim]=-1;
			for(register int i=max(s[lim]-'a'+1,0),p;i<26;++i){
				p=nxt[i][now];
				if(p&&Q.query(Q.rt[p],l+lim-1,r,1,n)){
					npos[lim]=i;
					break;
				}
			}
			if(lim==m+1)break;
			now=nxt[s[lim]-'a'][now];
			if(!now||!Q.query(Q.rt[now],l+lim-1,r,1,n))break;
		}
		while(lim&&npos[lim]==-1)--lim;
		if(lim){
			for(register int i=1;i<lim;++i)putchar(s[i]);
			putchar('a'+npos[lim]);
			putchar('\n');
		}
		else puts("-1");
	}
}T;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	T.reset();
	for(register int i=1;i<=n;++i)
		T.insert(s[i]-'a');
	T.build();
	T.dfs(1);
	for(register int t=read();t;--t)
		T.query();
	return 0;
}