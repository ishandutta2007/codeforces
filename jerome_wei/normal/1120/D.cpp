#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int hed[N],to[N<<1],nxt[N<<1],cnt;
inline void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
int n;
int c[N];
int best[N][2];ll f[N][3];
int lf[N];
ll t[N];
//1: no_rest 0: rest
inline void dfs(int x,int pre){
	int t=0;
	best[x][0]=0;// not choosing any
	best[x][1]=0;//chose subtree only
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);++t;
		f[x][0]=f[x][0]+f[v][1];
		if(f[x][0] > f[x][1]+f[v][0]){
			f[x][0]=f[x][1]+f[v][0];
			best[x][0]=v;
		}
		f[x][1]=f[x][1]+f[v][1];
	}
	if(t){
		if(f[x][1]>f[x][0]+c[x]){
			f[x][1]=f[x][0]+c[x];
			best[x][1]=best[x][0];
		}
	}else {
		lf[x]=1;
		f[x][0]=0, f[x][1]=c[x];
	}
}
int stk[N],top;
bool vst[N][2];
inline void dfs2(int x,int pre,int type){
	if(vst[x][type])return ;
	vst[x][type]=1;
	if(lf[x]){
		if(type)stk[++top]=x;
		return ;
	}
	if(type==0){
		ll MN=1000000000000000000;int sz=0;
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];if(v==pre)continue;
			t[v]=-f[v][1]+f[v][0];
			if(t[v]<MN){
				sz=1;MN=t[v];
			}else if(t[v]==MN){
				sz++;
			}
		}
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];if(v==pre)continue;
			t[v]=-f[v][1]+f[v][0];
			if(t[v]==MN){
				dfs2(v,x,0);
				if(sz>1)dfs2(v,x,1);
			}else dfs2(v,x,1);
		}
		
	}
	else if(type==1){
		ll MN=0;int sz=0;
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];if(v==pre)continue;
			t[v]=-f[v][1]+f[v][0]+c[x];
			if(t[v]<MN){
				MN=t[v],sz=1;
			}else if(t[v]==MN){
				++sz;
			}
		}
		if(sz)stk[++top]=x;
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];if(v==pre)continue;
			t[v]=-f[v][1]+f[v][0]+c[x];
			if(t[v]==MN){
				dfs2(v,x,0);
				if(sz>1||MN==0)dfs2(v,x,1);
			}else dfs2(v,x,1);
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	dfs(1,0);
	dfs2(1,0,1);
	cout<<f[1][1]<<" "<<top<<endl;
	sort(stk+1,stk+top+1);
	for(int i=1;i<=top;i++)printf("%d ",stk[i]);
}