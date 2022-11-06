#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[N*2],ne[N*2],la[N],len[N*2],t;
int res,mxl,u,v,n,q,ans;
void link(int x,int y,int z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
}
struct acut{
	int dep[N],mxd[N],ld[N],fa[N],hs[N],t,ty[N];
	int pre[N][20],px[N];
	vector<pair<int,int> > r; 
	void dfs2(int x){
		ld[x]=hs[fa[x]]==x?ld[fa[x]]:x;
		for (int y=la[x];y;y=ne[y])
			if (fa[x]!=w[y])dfs2(w[y]);
	}
	void dfs1(int x){
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (z==fa[x])continue;
			pre[z][0]=fa[z]=x;
			for (int i=1;i<20;i++)pre[z][i]=pre[pre[z][i-1]][i-1];
			mxd[z]=dep[z]=dep[x]+len[y];
			dfs1(z);
			mxd[x]=max(mxd[x],mxd[z]);
			if (mxd[x]==mxd[z])hs[x]=z;
		}
	}
	void init(int x){
		dfs1(x);
		dfs2(x);
		for (int i=1;i<=n;i++)
			if (ld[i]==i)r.push_back(make_pair(mxd[i]-dep[fa[i]],i));
		sort(r.begin(),r.end());
		reverse(r.begin(),r.end());
		for (int i=0;i<r.size();i++)
			ty[r[i].second]=i+1,px[i+1]=r[i].first+px[i];
		for (int i=1;i<=n;i++)ty[i]=ty[ld[i]];
	}
	int qsum(int x,int q){
		q=min(q,(int)r.size());
		int ans=px[q];
		if (ty[x]>q){
			int y=x;
			for (int u=19;u>=0;u--)
				if (ty[pre[y][u]]>q)y=pre[y][u];
			ans=max(px[q-1],ans-(mxd[fa[y]]-dep[fa[y]]))+mxd[x]-dep[fa[y]];
		}
		return ans;
	}
}A,B;
void go(int x,int fa,int dep){
	if (dep>mxl)res=x,mxl=dep;
	for (int y=la[x];y;y=ne[y])
		if (w[y]!=fa)go(w[y],x,dep+len[y]);
}
int main(){
	cin>>n>>q;
	for (int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z);
		link(y,x,z);
	}
	go(1,0,0);
	go(u=res,0,mxl);
	v=res;
	A.init(u);
	B.init(v);
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+ans-1)%n+1;
		y=(y+ans-1)%n+1;
		ans=max(A.qsum(x,2*y-1),B.qsum(x,2*y-1));
		printf("%d\n",ans);
	}
}