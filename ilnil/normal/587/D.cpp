#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define NO printf("No"),exit(0)
#define pb push_back
using namespace std;
const int N=3e5+5;
int n,m,x,y,c,d[N],r,an,mi;
struct edge{int c,i;};
vector<edge>e[N];
map<int,int>ct,w;
struct two_sat{
	int tt,m;
	int be[N],df[N],lo[N],z[N],ds,bs,zs;
	vector<int>b[N],b2[N],r[N],hv[N];
	bool ex[N],zz[N],can[N];
	void link(int x,int y){
		b[x].pb(y);
	}
	void tar(int x){
		df[x]=lo[x]=++ds;z[++zs]=x;zz[x]=1;
		for(int i:b[x])if(df[i]){
			if(zz[i])lo[x]=min(lo[x],df[i]);
		}else{
			tar(i);lo[x]=min(lo[x],lo[i]);
		}
		if(lo[x]==df[x])
			for(++bs;zz[x];zz[z[zs--]]=0)be[z[zs]]=bs,hv[bs].pb(z[zs]);
	}
	void dfs(int x){
		ex[x]=1;
		for(int i:b2[x])if(!ex[i])dfs(i);
	}
	bool init(){
		fo(i,1,tt)if(!df[i])tar(i);
		fo(i,1,m)if(be[i]==be[i+m])return 1;
		fo(i,1,tt)for(int j:b[i])
			if(be[i]!=be[j])
				b2[be[i]].pb(be[j]),r[be[j]].pb(be[i]);
		return 0;
	}
	void reset(){
		fo(i,1,bs)ex[i]=0;
	}
	void set2(int x){
		ex[x]=1;
		for(int i:b2[x])if(!ex[i])set2(i);
	}
	void set(int x){
		if(!ex[be[x]])set2(be[x]);
	}
	bool ck(){
		fo(i,1,m)if(ex[be[i]]&&ex[be[i+m]])return 0;
		return 1;
	}
	void reset2(){
		fo(i,1,bs)ex[i]=0;
		fo(i,1,tt)can[i]=0;
	}
	bool is(int x){
		for(int i:hv[x])
			if(i<=m&&ex[be[i+m]]||m<i&&i<=m*2&&ex[be[i-m]])return 0;
		return 1;
	}
	void put(int x){
		ex[x]=1;
		for(int i:hv[x])can[i]=1;
		df[++ds]=x;
	}
	void work(){
		ds=0;
		fo(i,1,bs)if(ex[i])put(i);
		fo(i,1,bs)lo[i]=ex[i]?0:b2[i].size(),(!lo[i]&&!ex[i]&&is(i)?put(i),0:0);
		for(int l=0,x;x=df[++l],l<=ds;)
			for(int i:r[x])
				if(!--lo[i]&&is(i))
					put(i);
	}
}A;
bool ck(){
	A.reset();
	fo(i,1,m)if(d[i]>mi)A.set(i);
	return A.ck();
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	fo(i,1,m)cin>>x>>y>>c>>d[i],r=max(r,d[i]),e[x].pb((edge){c,i}),e[y].pb((edge){c,i});
	A.tt=m*2;A.m=m;
	fo(x,1,n){
		int cnt=0,col=0;
		for(edge j:e[x]){
			++ct[j.c];
			if(ct[j.c]>2)NO;
			if(ct[j.c]==2&&++cnt==2)NO;
			if(w[j.c]){
				col=j.c;
				A.link(w[j.c],j.i+m);
				A.link(j.i+m,w[j.c]);
				A.link(w[j.c]+m,j.i);
				A.link(j.i,w[j.c]+m);
			}else w[j.c]=j.i;
		}
		for(edge j:e[x])(col&&col!=j.c?A.link(j.i+m,j.i),0:0);
		ct.clear();w.clear();
		if(!col){
			int st=A.tt;
			for(edge j:e[x]){
				if(A.tt++>st)
					A.link(A.tt,A.tt-1),A.link(j.i+m,A.tt-1);
				A.link(A.tt,j.i);
			}
			st=A.tt;
			fd(j,0,e[x].size()-1){
				if(A.tt++>st)A.link(A.tt,A.tt-1),A.link(e[x][j].i+m,A.tt-1);
				A.link(A.tt,e[x][j].i);
			}
		}
	}
	if(A.init())NO;
	for(int l=0;mi=l+r>>1,l<=r;)
		if(ck())an=mi,r=mi-1;else l=mi+1;
	A.reset2();
	fo(i,1,m)if(d[i]>an)A.set(i);
	A.work();
	int cnt=0;
	fo(i,1,m)if(A.can[i+m])++cnt;
	printf("Yes\n%d %d\n",an,cnt);
	fo(i,1,m)if(A.can[i+m])printf("%d ",i);
	
}