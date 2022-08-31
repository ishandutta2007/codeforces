#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

int n;
int v[2][800001];
int Nxt[2][800001],last[800001];
int Abs(int x){
	return x<0?-x:x;
}
void solve(int *a,int *b){
	memset(last,0,sizeof last);
	for(int i=1;i<=(n<<1);++i){
		int &p=last[Abs(a[i])];
		if(p){
			b[i]=p;
			b[p]=i;
		}
		else p=i;
	}
}
int ans[800001];
bool vis[800001];
int stk[800010],top;
int val[800001];
int Last[800001],pre[800001];
int edg(int s,int t,int w){
	return (w^(v[w][s]<v[w][t]))?-1:1;
}
struct graph{
	int con[2][800001];
	void addedge(int u,int v){
//		printf("addedge %d %d\n",u,v);
		if(!u||!v)return;
		if(con[0][u])con[1][u]=v;
		else con[0][u]=v;
		if(con[0][v])con[1][v]=u;
		else con[0][v]=u;
	}
	void deledge(int u,int v){
//		printf("deledge %d %d\n",u,v);
		if(!u||!v)return;
		if(con[1][u]==v)con[1][u]=0;
		else con[0][u]=con[1][u],con[1][u]=0;
		if(con[1][v]==u)con[1][v]=0;
		else con[0][v]=con[1][v],con[1][v]=0;
	}
	int find(int u,int v){
		return con[0][u]==v?con[1][u]:con[0][u];
	}
}g1,g2;
int cnt;
struct info{
	int fst,skd,min,max,lst,skdmn,lstmn;
};
info solve(int l,int r){
//	printf("solve %d %d\n",l,r);
	if(l>r){
		int u=++cnt,v=++cnt;
		g1.addedge(u,v);
		g1.addedge(u,v);
		g2.addedge(u,v);
		return (info){u,v,u,v,v,u,u};
	}
	if(val[l]!=val[r]){
		int u=++cnt,v=++cnt;
		info now=solve(l+1,r-1);
		if(val[l]==-1){
			g1.addedge(u,v);
			g1.deledge(now.fst,now.skd);
			g1.addedge(v,now.skd);
			g1.addedge(now.fst,u);
			g2.addedge(u,v);
			std::swap(now.min,now.max);
			g2.addedge(v,now.min);
			return (info){u,v,u,now.max,now.fst,u,g2.con[0][now.fst]};
		}
		else{
			int x=now.lst;
			g1.addedge(u,v);
			g1.deledge(now.fst,x);
			g1.addedge(u,now.fst);
			g1.addedge(v,x);
			g2.addedge(u,v);
			std::swap(now.min,now.max);
			g2.addedge(v,now.min);
			return (info){u,now.fst,u,now.max,v,g2.con[0][now.fst],u};
		}
	}
	else{
		int x=pre[r];
		assert(pre[r]>=l);
		info v1=solve(l,x),v2=solve(x+1,r);
//		printf("%d %d %d\n",v1.lst,g2.con[0][v1.lst],g2.con[1][v1.lst]);
		g1.deledge(v1.lst,v1.fst);
		int y=g1.con[0][v1.lst];
		g1.deledge(v2.skd,v2.fst);
		g1.deledge(v2.lst,v2.fst);
		g1.addedge(v2.lst,v1.fst);
		g1.deledge(v1.lst,y);
		g1.addedge(y,v2.skd);
		v2.min=g2.con[0][v2.min];
		g2.deledge(v2.min,v2.fst);
		g2.deledge(v1.lstmn,v1.lst);
		int z=g2.con[0][v1.lst];
		g2.deledge(z,v1.lst);
		g2.addedge(v1.lstmn,v2.min);
		g2.addedge(v2.max,z);
		int t1,t2;
		if(v1.skdmn==v1.lst)t1=v2.max;
		else t1=v1.skdmn;
		if(v2.lstmn==v2.fst)t2=v1.lstmn;
		else t2=v2.lstmn;
		return (info){v1.fst,v1.skd,v1.fst,(v1.max==v1.lst)?v2.max:v1.max,v2.lst,t1,t2};
	}
}
int Prev[800001],Next[800001];
int ord[800001],Ans[800001],len;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);++i)scanf("%d%d",&v[0][i],&v[1][i]);
	solve(v[0],Nxt[0]);
	solve(v[1],Nxt[1]);
	for(int i=1;i<=(n<<1);++i)
		if(!vis[i]){
			int tem=i,last=0;
			top=0;
			while(!vis[tem]){
				vis[tem]=1;
				stk[++top]=tem;
				tem=Nxt[last][tem];
				last^=1;
			}
			int cnt=edg(stk[top],stk[1],1);
			for(int i=1;i<top;++i)cnt+=edg(stk[i],stk[i+1],(i&1)^1);
			if(cnt==-2){
				std::reverse(stk+1,stk+top+1);
				cnt=-cnt;
			}
			if(cnt!=2){
				puts("NO");
				return 0;
			}
			int p;
			stk[0]=stk[top];
			stk[top+1]=stk[1];
			for(int i=1;i<=top;++i)
				if(edg(stk[i-1],stk[i],(i&1))==1&&edg(stk[i],stk[i+1],(i&1)^1)==1&&v[0][stk[i]]>0)p=i;
			int now=0;
			for(int i=p;i<=top;++i)val[++now]=edg(stk[i],stk[i+1],(i&1)^1);
			for(int i=1;i<p;++i)val[++now]=edg(stk[i],stk[i+1],(i&1)^1);
			for(int i=1,cnt=400000;i<=now;++i){
				cnt+=val[i];
				if(Last[cnt])pre[i]=Last[cnt];
				Last[cnt]=i;
			}
			for(int i=1,cnt=400000;i<=now;++i){
				cnt+=val[i];
				Last[cnt]=0;
			}
//			printf("%d\n",p);
//			for(int i=1;i<=now;++i)printf("%d ",val[i]);putchar('\n');
//			for(int i=1;i<=now;++i)printf("(%d %d)",v[0][stk[i]],v[1][stk[i]]);putchar('\n');
			info ans=solve(2,now-1);
			for(int i=1,u=ans.min;i<=top;++i){
				ord[i]=u;
				if(i<top){
					int m=g2.con[0][u];
					g2.deledge(u,m);
					u=m;
				}
			}
			g1.deledge(ans.fst,ans.lst);
			int u=ans.fst;
			for(int i=p;i<=top;++i){
//				printf("%d %d\n",u,stk[i]);
				Ans[u]=stk[i];
					int m=g1.con[0][u];
					g1.deledge(u,m);
					u=m;
			}
			for(int i=1;i<p;++i){
//				printf("%d\n",u);
				Ans[u]=stk[i];
					int m=g1.con[0][u];
					g1.deledge(u,m);
					u=m;
			}
//			for(;;){
//				int l,r;
//				scanf("%d%d",&l,&r);
//				info ans=solve(l,r);
//				g1.deledge(ans.fst,ans.lst);
//				for(int i=1,u=ans.fst;i<=r-l+3;++i){
//					printf("%d ",u);
//					int m=g1.con[0][u];
//					g1.deledge(u,m);
//					u=m;
//				}putchar('\n');
//				for(int i=1,u=ans.min;i<=r-l+3;++i){
//					printf("%d ",u);
//					int m=g2.con[0][u];
//					g2.deledge(u,m);
//					u=m;
//				}putchar('\n');
//				printf("%d %d %d %d %d %d %d\n",ans.fst,ans.skd,ans.min,ans.max,ans.lst,ans.skdmn,ans.lstmn);
//			}
			for(int i=1;i<=top;++i)::ans[++len]=Ans[ord[i]];
		}
	puts("YES");
	for(int i=1;i<=(n<<1);++i)printf("%d %d\n",v[0][ans[i]],v[1][ans[i]]);
}