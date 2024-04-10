#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt,rt;
int ch[1100000][2],fa[1100000],sz[1100000];
ll val[1100000],tag[1100000];
inline int dir(int x){ return x==ch[fa[x]][1];}
inline void upd(int x,ll v){ val[x]+=v; tag[x]+=v;}
inline void pushup(int x){ sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;}
void pushdown(int x){
	if (!tag[x]) return;
	if (ch[x][0]) upd(ch[x][0],tag[x]);
	if (ch[x][1]) upd(ch[x][1],tag[x]);
	tag[x]=0;
}
void pushall(int x){
	if (fa[x]) pushall(fa[x]);
	pushdown(x);
}
void rotate(int x){
	int y=fa[x],z=fa[y],k=dir(x);

	if (z) ch[z][dir(y)]=x;
	else rt=x;
	fa[x]=z;

	if (ch[x][k^1]) fa[ch[x][k^1]]=y;
	ch[y][k]=ch[x][k^1];
	
	ch[x][k^1]=y; fa[y]=x;
	pushup(y); pushup(x);
}
void splay(int x){
	pushall(x);
	for (;fa[x];rotate(x))
		if (fa[fa[x]]) rotate(dir(fa[x])==dir(x)?fa[x]:x);
}
ll kth(int x){
	if (x==0) return 0;
	int now=rt;
	while (x){
		pushdown(now);
		if (x<=sz[ch[now][0]]) now=ch[now][0];
		else if (x==sz[ch[now][0]]+1){ splay(now); return val[rt];}
		else x-=(sz[ch[now][0]]+1),now=ch[now][1];
	}
	return -1;
}
int find(int x,int tot,int v){
	if (!x) return -1;
	pushdown(x);
	int now=tot+sz[ch[x][0]];
	if (val[x]>1ll*(now+1)*v){
		int tmp=find(ch[x][1],now+1,v);
		if (tmp!=-1) return tmp;
		else{ splay(x); return now+1;}
	} else return find(ch[x][0],tot,v);
}
int main(){ 
	scanf("%d",&n);
	int x;
	scanf("%d",&x);
	cnt=1; val[1]=x; sz[1]=1; rt=1;
	for (int i=2;i<=n;i++){
		scanf("%d",&x);
		int res=find(rt,0,x);
		if (res==-1){
			cnt++; sz[cnt]=1; val[cnt]=0;
			ch[cnt][1]=rt; fa[rt]=cnt;
			rt=cnt; pushup(rt);
		} else{
			cnt++; sz[cnt]=1; val[cnt]=1ll*x*res;
			if (ch[rt][1]){ fa[ch[rt][1]]=cnt; ch[cnt][1]=ch[rt][1];}
			ch[rt][1]=cnt; fa[cnt]=rt;
			pushup(cnt); pushup(rt);
		}
		upd(cnt,x);
		ll now=0;
		/*for (int j=0;j<=i;j++){
			now+=kth(j);
			printf("%lld ",now);
		}
		puts("");*/
	}
	ll now=0,ans=0;
	for (int i=0;i<=n;i++){
		now+=kth(i);
		ans=max(ans,now);
//		printf("%lld ",now);
	}
	printf("%lld\n",ans);
	return 0;
}