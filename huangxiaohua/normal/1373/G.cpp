#include<bits/stdc++.h>
#define maxn 400005
#define ll long long
using namespace std;
ll aa[maxn];
ll t[maxn*4],tag[maxn*4];
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

int i,j,k,n,m,x,vis[400500];

int main(){
	scanf("%d%d%d",&n,&k,&m);
	map<pair<int,int>,int>mp;
	while(m--){
		scanf("%d%d",&i,&j);
		x=abs(i-k)+j;
		if(!mp[{i,j}]){
			if(!vis[x])add(1,n+n,1,x,x,x-1);
			add(1,n+n,1,1,x,1);vis[x]++;
		}
		else{
			vis[x]--;add(1,n+n,1,1,x,-1);
			if(!vis[x])add(1,n+n,1,x,x,1-x);
		}
		mp[{i,j}]^=1;
		printf("%d\n",max(query(1,n+n,1,1,n+n)-n,0));
	}
}