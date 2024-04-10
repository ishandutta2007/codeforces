#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int N=300000;
const int M=600009;
int q,n;
int f[M];
map<pii,int>mp;
vector<pii>t[M<<2];
int top=0,s[M];
int px[M],py[M],siz[M];
ll ans;
void update(int now,int l,int r,int x,int y,pii p){
	if(x<=l&&r<=y){
		t[now].eb(p);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)update(now<<1,l,mid,x,y,p);
	if(y>mid)update(now<<1|1,mid+1,r,x,y,p);
}
int find(int x){
	return f[x]==x?x:find(f[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(siz[x]<siz[y])swap(x,y);
	ans-=1ll*px[x]*py[x]+1ll*px[y]*py[y];
	f[y]=x;
	siz[x]+=siz[y];
	px[x]+=px[y];
	py[x]+=py[y];
	ans+=1ll*px[x]*py[x];
	s[++top]=y;
}
void del(int x,int y){
	ans-=1ll*px[x]*py[x];
	siz[x]-=siz[y];
	px[x]-=px[y];
	py[x]-=py[y];
	ans+=1ll*px[x]*py[x]+1ll*px[y]*py[y];
	f[y]=y;
}
void solve(int now,int l,int r){
	int last=top;
	for(auto o:t[now]){
		merge(o.fi,o.se);
	}
	if(l==r){
		printf("%lld ",ans);
	}
	if(l<r){
		int mid=l+r>>1;
		solve(now<<1,l,mid);
		solve(now<<1|1,mid+1,r);
	}
	for(int i=top;i>last;--i){
		del(f[s[i]],s[i]);
	}
	top=last;
}
int main(){
	scanf("%d",&q);
	for(int i=1;i<=N;++i)f[i]=i,f[i+N]=i+N,siz[i]=siz[i+N]=1,px[i]=1,py[i+N]=1;
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		y+=N;
		auto p=make_pair(x,y);
		if(mp.count(p)){
			update(1,1,q,mp[p],i-1,p);
			mp.erase(p);
		}
		else mp[p]=i;
	}
	for(auto o:mp){
		update(1,1,q,o.se,q,o.fi);
	}
	solve(1,1,q);
	return 0;
}
/*
1
2
ab
ba
*/