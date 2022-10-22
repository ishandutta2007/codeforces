#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int inf=1e9;
const int N=5e5+10;
const LL P=998244353; 

int n,m,K;
int c[N];
struct R{
	int u,v;
}d[N];
bool cmp(R x,R y){
	if(c[x.u]!=c[y.u]) return c[x.u]<c[y.u];
	else return c[x.v]<c[y.v];
}
int fa[N],g[N],sz[N];
bool vis[N];
pair<int,int> find(pair<int,int> x){
	if(x.first==fa[x.first]) return x;
	return find(make_pair(fa[x.first],x.second^g[x.first]));
}
void check1(int u,int v){
	if(vis[c[u]]) return;
	pair<int,int> A,B;
	A=find(make_pair(u,0));
	B=find(make_pair(v,0));
	if(A.first==B.first){
		if(A.second!=B.second) return;
		vis[c[u]]=1;
		return;
	}
	if(sz[A.first]<sz[B.first]) swap(A,B);
	fa[B.first]=A.first;
	g[B.first]=1^A.second^B.second;
	sz[A.first]+=sz[B.first];
}
LL ans;
int tp=0;
int st[N];
LL check2(int l,int r){
	tp=0;
	LL res=0;
	int x;
	if(vis[c[d[l].u]]||vis[c[d[l].v]]) return 0;
	pair<int,int> A,B;
	for(int i=l;i<=r;++i){
		A=find(make_pair(d[i].u,0));
		B=find(make_pair(d[i].v,0));
		if(A.first==B.first){
			if(A.second!=B.second) continue;
			res=-1;break;
		}
		if(sz[A.first]<sz[B.first]) swap(A,B);
		fa[B.first]=A.first;
		g[B.first]=1^A.second^B.second;
		sz[A.first]+=sz[B.first];
		st[++tp]=B.first;
	}
	while(tp>0){
		x=st[tp];--tp;
		sz[fa[x]]-=sz[x];
		g[x]=0;
		fa[x]=x;
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;++i) {
		scanf("%d",&c[i]);
		fa[i]=i;
		sz[i]=1;
		g[i]=0;
	}
	int now=0;
	while(now<m){
		++now;
		scanf("%d%d",&d[now].u,&d[now].v);
		if(c[d[now].u]==c[d[now].v]){
			check1(d[now].u,d[now].v);
			--now;--m;
		}
		else{
			if(c[d[now].u]>c[d[now].v]) swap(d[now].u,d[now].v);
		}
	}
	ans=0;
	for(int i=1;i<=K;++i){
		if(!vis[i]) ++ans;
	}
	//cout<<ans<<endl;
	ans=(LL)ans*(LL)(ans-1)/(LL)2;
	//cout<<ans<<endl;
	if(m>0){
		sort(d+1,d+1+m,cmp);
		for(int i=1,j;i<=m;i=j+1){
			j=i;
			while(j<m&&c[d[j+1].u]==c[d[j].u]&&c[d[j+1].v]==c[d[j].v]) ++j;
			ans+=check2(i,j);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
/*
8 7 4
1 2 3 4 1 2 3 4
1 2
2 5
2 6
2 7
6 7
6 8
1 6

*/