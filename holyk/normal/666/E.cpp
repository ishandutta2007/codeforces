#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)

typedef long long ll;

#define gc getchar()
inline int read(){char c,p=0;int w;
	while(!isdigit(c=gc))if(c=='-')p=1;w=c&15;
	while(isdigit(c=gc))w=w*10+(c&15);return p?-w:w;
}

template<typename T,typename U>inline bool smin(T&x,const U&y){return y<x?x=y,1:0;}
template<typename T,typename U>inline bool smax(T&x,const U&y){return x<y?x=y,1:0;}

const int N=1e5+5,M=5e5+5;
struct data{
	int x,id;
	data(int x=0,int id=0):x(x),id(id){}
	inline bool operator<(const data&r)const{return x<r.x||x==r.x&&id>r.id;}
};
struct Node{int ls,rs;data w;}t[N*30];
int tr;
#define pushup(o) t[o].w=std::max(t[t[o].ls].w,t[t[o].rs].w)
void ins(int&o,int l,int r,int x){
	if(!o)o=++tr;
	if(l==r)return (void)(++t[o].w.x,t[o].w.id=l);
	int mid=l+r>>1;
	x<=mid?ins(t[o].ls,l,mid,x):ins(t[o].rs,mid+1,r,x);
	pushup(o);
}
data ask(int o,int l,int r,int x,int y){
	if(!o||y<l||x>r)return 0;
	if(x<=l&&r<=y)return t[o].w;
	int mid=l+r>>1;
	return std::max(ask(t[o].ls,l,mid,x,y),ask(t[o].rs,mid+1,r,x,y));
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	const int z=++tr;
	if(l==r)return t[z].w=data(t[x].w.x+t[y].w.x,l),z;
	int mid=l+r>>1;
	t[z].ls=merge(t[x].ls,t[y].ls,l,mid);
	t[z].rs=merge(t[x].rs,t[y].rs,mid+1,r);
	return pushup(z),z;
}
int m,ch[N][26],len[N],fa[20][N],last,cnt,rt[N];
void ins(int x,int id){
	if(ch[last][x]&&len[ch[last][x]]==len[last]+1){
		last=ch[last][x];ins(rt[last],1,m,id);return;
	}
	int p=last,np=last=++cnt,q;len[np]=len[p]+1;ins(rt[np],1,m,id);
	for(;p&&!ch[p][x];p=fa[0][p])ch[p][x]=np;
	if(!p)fa[0][np]=1;else if(len[q=ch[p][x]]==len[p]+1)fa[0][np]=q;
	else{
		int nq=++cnt;len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof ch[q]);
		fa[0][nq]=fa[0][q],fa[0][q]=fa[0][np]=nq;
		for(;p&&ch[p][x]==q;p=fa[0][p])ch[p][x]=nq;
	}
}
int head[N],to[N],ne[N],tot;
inline void add(int x,int y){to[++tot]=y,ne[tot]=head[x];head[x]=tot;}
void go(int x){for(int i=head[x];i;i=ne[i])go(to[i]),rt[x]=merge(rt[x],rt[to[i]],1,m);}
int n,pos[M],tlen[M];
char s[M],ts[N];
int main(){
	scanf("%s",s+1);n=strlen(s+1);cnt=1;
	
	m=read();
	REP(j,1,m){
		scanf("%s",ts+1);
		int l=strlen(ts+1);last=1;
		REP(i,1,l)ins(ts[i]-'a',j);
	}
	REP(i,1,17)REP(x,1,cnt)fa[i][x]=fa[i-1][fa[i-1][x]];
	
	int p=1,nw=0;
	REP(i,1,n){
		int x=s[i]-'a';
		for(;p>1&&!ch[p][x];nw=len[p=fa[0][p]]);
		if(ch[p][x])pos[i]=p=ch[p][x],tlen[i]=++nw;
	}
	REP(i,2,cnt)add(fa[0][i],i);go(1);
	
	int q=read();
	while(q--){
		int l=read(),r=read(),t;nw=read(),t=read();nw=t-nw+1;
		if(tlen[t]<nw)printf("%d 0\n",l);
		else{
			p=pos[t];
			for(int i=17;~i;--i)if(len[fa[i][p]]>=nw)p=fa[i][p];
			
			data ans=ask(rt[p],1,m,l,r);
			
			if(ans.x)printf("%d %d\n",ans.id,ans.x);
			else printf("%d 0\n",l);
		}
	}
	return 0;
}