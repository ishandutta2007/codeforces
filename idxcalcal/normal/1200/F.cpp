#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
    static char buf[rlen],*ib,*ob;
    (ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
    return ib==ob?-1:*ib++;
}
inline int read(){
   	int ans=0;
    bool f=1;
    char ch=gc();
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
    return f?ans:-ans;
}
const int N=3000005,lim=2520;
typedef pair<int,int> pii;
inline int Idx(pii x){return (x.fi-1)*lim+x.se+1;}
int n,a[N],md[N],nxt[N],tot=0,mp[N],du[N],ans[N];
bool in[N],inp[N],vis[N];
vector<int>trans[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)a[i]=(read()%lim+lim)%lim;
	for(ri i=1;i<=n;++i){
		md[i]=read();
		for(ri j=0;j<md[i];++j)trans[i].push_back(read());
		for(ri j=0;j<lim;++j)mp[Idx(pii(i,j))]=i;
	}
	int up=Idx(pii(1,0)),down=Idx(pii(n,lim-1));
	for(ri u=1,v,B;u<=n;++u){
		for(ri t,A=0;A<lim;++A){
			B=(A+a[u])%lim;
			t=B%md[u];
			v=trans[u][t];
			nxt[Idx(pii(u,A))]=Idx(pii(v,B)),++du[Idx(pii(v,B))];
		}
	}
	set<int>S;
	vector<int>t;
	for(ri i=up,x;i<=down;++i){
		if(du[i])continue;
		for(ri j=i;;j=nxt[j]){if(in[j]){x=j;break;}in[j]=1;}
		if(!inp[x]){
			S.clear();
			inp[x]=1,S.insert(mp[x]);
			for(ri j=nxt[x];j!=x;j=nxt[j])inp[j]=1,S.insert(mp[j]);
			ans[x]=S.size();
			for(ri j=nxt[x];j!=x;j=nxt[j])ans[j]=S.size();
		}
		t.clear();
		for(ri j=i;j!=x;j=nxt[j])t.push_back(j),inp[j]=1;
		for(ri j=t.size()-1;~j;--j)ans[t[j]]=ans[nxt[t[j]]];
	}
	for(ri i=up,x;i<=down;++i){
		if(in[i])continue;
		S.clear();
		x=i;
		inp[x]=1,S.insert(mp[x]),in[x]=1;
		for(ri j=nxt[x];j!=x;j=nxt[j])in[j]=j,inp[j]=1,S.insert(mp[j]);
		ans[x]=S.size();
		for(ri j=nxt[x];j!=x;j=nxt[j])ans[j]=S.size();
	}
	for(ri x,y,tt=read();tt;--tt){
		x=read(),y=(read()%lim+lim)%lim;
		cout<<ans[Idx(pii(x,y))]<<'\n';
	}
	return 0;
}