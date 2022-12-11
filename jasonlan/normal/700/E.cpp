#include<iostream>
#include<cstdio>
#include<cstring>
#define mid ((l+r)>>1)
using namespace std;
const int SIZE=410000,chrg=26;
int n,ans;
char s[SIZE];
inline int read(){
	int res=0;
	char ch=getchar(),ch2=ch;
	while(!isdigit(ch))ch2=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch2=='-'?-res:res;
}
struct Segment_Tree{
	int rt[SIZE],verx;
	int son[2][SIZE<<5];
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
		return query(son[0][p],lr,rr,l,mid)|query(son[1][p],lr,rr,mid+1,r);
	}
}Q;
struct GSA{
	int ver,last;
	int nxt[chrg][SIZE],link[SIZE],len[SIZE];
	int epos[SIZE],f[SIZE],fa[SIZE];
	int cnt[SIZE],q[SIZE];
	void init(){
		link[0]=-1;
		len[0]=ver=0;
	}
	void insertSAM(int no,int ch){
		int cur=++ver,p=last;
		len[cur]=len[last]+1;
		epos[cur]=no;
		Q.modify(Q.rt[cur],no,1,n);
		while(~p&&!nxt[ch][p]){
			nxt[ch][p]=cur;
			p=link[p];
		}
		if(p==-1)
			link[cur]=0;
		else{
			int q=nxt[ch][p];
			if(len[q]==len[p]+1)link[cur]=q;
			else{
				int clone=++ver;
				for(register int i=0;i<chrg;++i)
					nxt[i][clone]=nxt[i][q];
				len[clone]=len[p]+1;
				while(~p&&nxt[ch][p]==q){
					nxt[ch][p]=clone;
					p=link[p];
				}
				link[clone]=link[q];
				epos[clone]=epos[q];
				link[q]=link[cur]=clone;
			}
		}
		last=cur;
	}
	void toposort(){
		for(register int i=1;i<=ver;++i)++cnt[len[i]];
		for(register int i=1;i<=n;++i)cnt[i]+=cnt[i-1];
		for(register int i=ver;i;--i)q[cnt[len[i]]--]=i;
	}
	void work(){
		for(register int i=ver,u,v;i;--i){
			u=q[i];v=link[u];
			Q.rt[v]=Q.merge(Q.rt[v],Q.rt[u],1,n);
		}
		for(register int i=1,u,v;i<=ver;++i){
			u=q[i];v=link[u];
			if(!v)f[u]=1,link[u]=u;
			else{
				if(Q.query(Q.rt[link[v]],epos[u]-len[u]+len[link[v]],epos[u]-1,1,n))
					f[u]=f[v]+1,link[u]=u;
				else
					f[u]=f[v],link[u]=link[v];
			}
			ans=max(ans,f[u]);
		}
	}
}T;
int main(){
	T.init();
	n=read();
	scanf("%s",s+1);
	for(register int i=1;i<=n;++i)
		T.insertSAM(i,s[i]-'a');
	T.toposort();
	T.work();
	printf("%d\n",ans);
	return 0;
}