#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;

int laz[mn*4],seg[mn*4];
void prop(int x){
	if(!laz[x])return;
	seg[x]+=laz[x];
	if(x*2+1<mn*4){
		laz[x*2]+=laz[x];
		laz[x*2+1]+=laz[x];
	}
	laz[x]=0;
}
void eval(int x){
	prop(x*2),prop(x*2+1);
	seg[x]=max(seg[x*2],seg[x*2+1]);
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,int c){
	if(l==a&&r==b)laz[x]+=c;
	else {
		prop(x);
		if(b<=mid)upd(x*2,l,mid,a,b,c);
		else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
		else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
		eval(x);
	}
}

pii qu_max(int x,int l,int r){
	prop(x);
	if(l==r)return {r,seg[x]};
	else{
		prop(x*2);
		if(seg[x]==seg[x*2])return qu_max(x*2,l,mid);
		else return qu_max(x*2+1,mid+1,r);
	}
}

vector<int>g[mn];
int o[mn],ct,s[mn],ro[mn],numl=0,par[mn];

void dfs(int x,int p){
	o[x]=ct++;
	ro[o[x]]=x;
	s[x]=1;
	if(g[x].size()==1&&x!=1)numl++;
	for(int y:g[x])if(y!=p){
		par[y]=x;
		dfs(y,x);
		s[x]+=s[y];
	}
}
bool vis[mn];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,1);
	if(numl<=k){
		k=min(k,max(numl,n/2));
		printf("%lld\n",1LL*k*(n-k));
		return 0;
	}
	int bl=0;
	for(int i=1;i<=n;i++){
		upd(1,0,n-1,o[i],o[i]+s[i]-1,1);
	}
	for(int i=0;i<k;i++){
		pii p = qu_max(1,0,n-1);
		bl+=p.second;
		for(int x=ro[p.first];x!=0;x=par[x]){
			if(vis[x])break;
			vis[x]=1;
			upd(1,0,n-1,o[x],o[x]+s[x]-1,-1);
		}
	}
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<=n-bl;i++){
		ans=min(ans,1LL*(k-i)*(n-k-i));
	}
	printf("%lld\n",ans);
}