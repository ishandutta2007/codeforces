#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t[4000050],tag[4000050];
vector<int> v[1005000];

inline void refresh(int now){
	t[now]=max(t[now<<1],t[now<<1|1]);
}
void pushdown(int l,int r,int now){
	if(l==r){
		tag[now]=0;
		return;
	}
	tag[now<<1]+=tag[now];
	tag[now<<1|1]+=tag[now];
	int mid=(l+r)>>1;
	t[now<<1]+=tag[now];
	t[now<<1|1]+=tag[now];
	tag[now]=0;
}
void add(int l,int r,int now,int LL,int RR,int data){
	if(LL<=l&&r<=RR){
		t[now]+=data;
		tag[now]+=data;
		return;
	}
	if(tag[now]) pushdown(l,r,now);
	int mid=(l+r)>>1;
	if(LL<=mid) add(l,mid,now<<1,LL,RR,data);
	if(mid<RR) add(mid+1,r,now<<1|1,LL,RR,data);
	refresh(now);
}
int query(int l,int r,int now,int LL,int RR){
	if(LL<=l&&r<=RR){
		return t[now];
	}
	if(tag[now]) pushdown(l,r,now);
	int mid=(l+r)>>1;int ans=-1e9;
	if(LL<=mid) ans=max(query(l,mid,now<<1,LL,RR),ans);
	if(mid<RR) ans=max(ans,query(mid+1,r,now<<1|1,LL,RR));
	refresh(now);
	return ans;
}

int i,j,k,n,m,st[1005000][2],siz[1005000],id[1005000],it,sb;
void dfs(int x){
	siz[x]++;
	for(auto i:v[x]){
		dfs(i);siz[x]+=siz[i];
	}
	id[x]=++it;
}

int main(){
	scanf("%d%d",&n,&sb);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		while(m&&st[m][1]<k){
			v[i].push_back(st[m][0]);m--;
		}
		st[++m][0]=i;st[m][1]=k;
	}
	n++;
	while(m){
		v[n].push_back(st[m][0]);m--;
	}
	dfs(n);
	for(i=1;i<=sb;i++){
		add(1,n,1,id[i]-siz[i]+1,id[i],1);
	}
	for(i=sb;i<n;i++){
		printf("%d ",t[1]);
		add(1,n,1,id[i+1]-siz[i+1]+1,id[i+1],1);
		add(1,n,1,id[i-sb+1]-siz[i-sb+1]+1,id[i-sb+1],-1);
	}
}