// Hydro submission #614c87ab478454b8ebea5098@1632406036815
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 100005
#define mp make_pair
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,v[N*2],w[N*2],head[N*2],nxt[N*2],cnt,f[N],siz[N],p,ffa[N],sum[N];
long long ans,dis[N];
set<int>st;
set<int>sub[N];
set<pair<int,int>>tot;
void add(int a,int b,int c){
	v[++cnt]=b;
	w[cnt]=c;
	nxt[cnt]=head[a];
	head[a]=cnt;
}
void dfs1(int x,int fa){
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(v[i]==fa)continue;
		dfs1(v[i],x);
		siz[x]+=siz[v[i]];
		f[x]=max(f[x],siz[v[i]]);
	}
	f[x]=max(f[x],n-siz[x]);
	if(f[x]<f[p])p=x;
}
void dfs2(int x,int fa){
	ans+=dis[x];
	for(int i=head[x];i;i=nxt[i]){
		if(v[i]==fa)continue;
		dis[v[i]]=dis[x]+w[i];
		dfs2(v[i],x);
	}
}
void doit(int x,int fa,int rt){
	ffa[x]=rt;sub[rt].insert(x);siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(v[i]==fa)continue;
		doit(v[i],x,rt);
		siz[x]+=siz[v[i]];
	}
}
int find(int x){
	set<pair<int,int> >::iterator it=tot.lower_bound(mp(n-x+1,0));
	int ff=0,GG=(*it).second;
	if(it!=tot.end()&&(*it).first==n-x+1&&GG!=ffa[x])ff=1;
	if(ffa[x]){
		tot.erase(mp(sum[ffa[x]],ffa[x]));
		sum[ffa[x]]--;
		tot.insert(mp(sum[ffa[x]],ffa[x]));
	}
	if(ff){
		int res=*sub[GG].begin();
		st.erase(res);sub[GG].erase(res);
		if(sub[GG].size())st.insert(*sub[GG].begin());
		tot.erase(mp(sum[ffa[res]],ffa[res]));
		sum[ffa[res]]--;
		tot.insert(mp(sum[ffa[res]],ffa[res]));
		return res;
	}else{
		set<int>::iterator itt=st.begin();
		if(ffa[x]==ffa[*itt]&&x!=p)itt++;
		st.erase(itt);
		int res=*itt;
		if(ffa[res]){
			sub[ffa[res]].erase(res);
			if(sub[ffa[res]].size())st.insert(*sub[ffa[res]].begin());
			tot.erase(mp(sum[ffa[res]],ffa[res]));
			sum[ffa[res]]--;
			tot.insert(mp(sum[ffa[res]],ffa[res]));
		}
		return res;
	}
	return 0;
}
signed main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	f[0]=0x3f3f3f3f;
	dfs1(1,0);dfs2(p,0);
	printf("%lld\n",ans*2);st.insert(p);
	for(int i=head[p];i;i=nxt[i]){
		doit(v[i],p,v[i]);
		sum[v[i]]=siz[v[i]]*2;
		siz[p]+=siz[v[i]];
		tot.insert(mp(sum[v[i]],v[i]));
		st.insert(*sub[v[i]].begin());
	}
	for(int i=1;i<=n;i++)printf("%d ",find(i));
	return 0;
}