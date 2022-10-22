#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
const int Maxm=50000;
const int Maxw=Maxm*100;
int n,m,qt[Maxm+5],ans[Maxm+5];
ll o,ql[Maxm+5],qr[Maxm+5];
std::vector<ll> v;
int tot,cnt,ls[Maxw+5],rs[Maxw+5],a[Maxw+5],rt,p[Maxw+5];
std::vector<int> e[Maxw+5],g[Maxw+5];
void modify(int &k,ll L,ll R,ll l=0,ll r=o-1){
	if(!k){
		k=++tot;
	}
	if(L<=l&&r<=R){
		a[k]=++cnt;
		return;
	}
	ll h=(l+r)>>1;
	if(L<=h){
		modify(ls[k],L,R,l,h);
	}
	if(h<R){
		modify(rs[k],L,R,h+1,r);
	}
}
void dfs(int k1,int k2,int d,int D){
	if(d>D){
		if(a[k1]){
			return;
		}
		dfs(ls[k1],ls[k2],d-1,D);
		dfs(rs[k1],rs[k2],d-1,D);
		return;
	}
	if(d==D){
		if(a[k1]){
			return;
		}
		dfs(ls[k1],rs[k2],d-1,D);
		return;
	}
	if(a[k1]&&a[k2]){
		e[a[k1]].push_back(a[k2]);
		e[a[k2]].push_back(a[k1]);
		return;
	}
	if(a[k1]){
		dfs(k1,ls[k2],d-1,D);
		dfs(k1,rs[k2],d-1,D);
		return;
	}
	if(a[k2]){
		dfs(ls[k1],k2,d-1,D);
		dfs(rs[k1],k2,d-1,D);
		return;
	}
	dfs(ls[k1],ls[k2],d-1,D);
	dfs(rs[k1],rs[k2],d-1,D);
}
void query(int k,ll L,ll R,int i,ll l=0,ll r=o-1){
	if(L<=l&&r<=R){
		p[a[k]]=i;
		g[i].push_back(a[k]);
		return;
	}
	ll h=(l+r)>>1;
	if(L<=h){
		query(ls[k],L,R,i,l,h);
	}
	if(h<R){
		query(rs[k],L,R,i,h+1,r);
	}
}
int f[Maxw+5];
int fnd(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=fnd(f[x]);
}
void ins(int x){
	f[x]=x;
	for(int i=0;i<(int)e[x].size();i++){
		if(f[e[x][i]]){
			f[fnd(x)]=fnd(e[x][i]);
		}
	}
}
int geta(int k,ll x){
	for(int i=n-1;i>=0;i--){
		if((x>>i)&1){
			k=rs[k];
		}
		else{
			k=ls[k];
		}
		if(a[k]){
			return a[k];
		}
	}
	return -1;
}
int main(){
	char ch[5];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s%lld%lld",ch,ql+i,qr+i);
		if(ch[0]=='a'){
			qt[i]=1;
		}
		else{
			v.push_back(ql[i]-1),v.push_back(qr[i]);
		}
	}
	o=1ll<<n;
	v.push_back(-1),v.push_back(o-1);
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<(int)v.size();i++){
		modify(rt,v[i-1]+1,v[i]);
	}
	for(int i=0;i<n;i++){
		dfs(rt,rt,n-1,i);
	}
	for(int i=1;i<=m;i++){
		if(!qt[i]){
			query(rt,ql[i],qr[i],i);
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!p[i]){
			ins(i);
		}
	}
	for(int i=m;i>0;i--){
		if(!qt[i]){
			for(int j=0;j<(int)g[i].size();j++){
				ins(g[i][j]);
			}
		}
		else{
			ql[i]=geta(rt,ql[i]);
			qr[i]=geta(rt,qr[i]);
			ans[i]=fnd(ql[i])==fnd(qr[i]);
		}
	}
	for(int i=1;i<=m;i++){
		if(qt[i]){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}