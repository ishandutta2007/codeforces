/* based on bzoj 2286 */
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int anc[N][22];
ll mn[N];
const ll INF=1000000000000000000;
int n,m;
int num,dfn[N],dep[N];
int point[N];
bool cmp(const int a,const int b) {
	return dfn[a]<dfn[b];
}
namespace Tr_all {
	int hed[N],to[N];ll val[N];int cnt,nxt[N];
	inline void adde(int u,int v,ll w) {
		++cnt;
		val[cnt]=w,to[cnt]=v,nxt[cnt]=hed[u];
		hed[u]=cnt;
	}
	inline void dfs(int x,int pre) {
		dfn[x]=++num;
		dep[x]=dep[pre]+1;
		if(x==1)mn[x]=INF;
		anc[x][0]=pre;
		for(int i=1; 1<<i<=n; i++) {
			anc[x][i]=anc[anc[x][i-1]][i-1];
		}
		for(int i=hed[x]; i; i=nxt[i]) {
			int v=to[i];
			if(v==pre)continue;
			mn[v]=min(mn[x],(ll)val[i]);
			dfs(v,x);
		}
	}
	int LCA(int x,int y) {
		if(dep[x]<dep[y])swap(x,y);
		for(int i=19; ~i; i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
		if(x==y)return x;
		for(int i=19; ~i; i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
		return anc[x][0];
	}
}
using Tr_all::LCA;
int MX,rt;
bool ch[N];int nowid;
ll dp[N];bool flg=0;
namespace Tr_cur {
	int hed[N],to[N],nxt[N],cnt;
	int H[N];
	inline void adde(int u,int v) {
		//cout<<u<<" "<<v<<endl;
		if(u==v)return;
		++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
		++cnt;to[cnt]=u,nxt[cnt]=hed[v];hed[v]=cnt;
	}
	inline void clear() {cnt=0;}
	inline void DP(int x,int pre) {
		H[x]=H[pre];
		if(ch[x]){
			ch[x]=0;
			if(H[x]>MX){flg=1;}
			//cout<<x<<" "<<H[x]<<endl;
			for(int i=MX;i;i--){
				dp[i]=dp[i]*max(0ll,(ll)(i-H[x]))%1000000007ll+dp[i-1];
				dp[i]%=1000000007ll;
			}
			dp[0]=0;
			H[x]++;
		}
		for(int i=hed[x]; i; i=nxt[i]) {
			int v=to[i];if(v==pre||v==x)continue;
			DP(v,x);
		}
		hed[x]=0;ch[x]=0;
		/* Myclear */

	}
}
using Tr_cur::DP;
int stk[N],top;
 
int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1; i<n; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		Tr_all::adde(u,v,1);Tr_all::adde(v,u,1);
	}
	Tr_all::dfs(1,0);
	while(m--) {
		int tot;
		scanf("%d",&tot);scanf("%d%d",&MX,&rt);
		for(int i=1; i<=tot; i++){ scanf("%d",&point[i]); ch[point[i]]=1;}
		point[++tot]=rt;
		sort(point+1,point+tot+1,cmp);
		stk[(top=1)]=1;
		/*insert*/
		for(int i=1; i<=tot; i++) {
			int u=point[i];
			int lca=LCA(u,stk[top]);
			if(top==1) {stk[++top]=u;continue;}
			if(lca==stk[top]){stk[++top]=u;continue;}
			while(top>1&&dep[stk[top-1]]>dep[lca]) {
				Tr_cur::adde(stk[top-1],stk[top]);
				--top;
			}
			if(dep[stk[top]]>dep[lca]) {
				Tr_cur::adde(lca,stk[top]);
				top--;
			}
			if(dep[stk[top]]<dep[lca]) stk[++top]=lca;
			stk[++top]=u;
		}
		while(--top) Tr_cur::adde(stk[top],stk[top+1]);
		/**/
		Tr_cur::H[rt]=0;flg=0;
		for(int i=0;i<=MX;i++){dp[i]=0;}
		dp[0]=1;
		DP(rt,0);
		ll ans=0;
		for(int i=1;i<=MX;i++){ans+=dp[i];ans%=1000000007;}
		printf("%lld\n",ans);
		Tr_cur::clear();
	}
}