#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,b[200500];

vector<int> v[200500];

int t[2000050],tag[2000050],a[2000050],res[2000050];

inline void refresh(int now){
	t[now]=max(t[now<<1],t[now<<1|1]);
}
void build(int l,int r,int now){
	if(l==r){
		t[now]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now<<1);
	build(mid+1,r,now<<1|1);
	refresh(now);
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

int t2[2000050],tag2[2000050],a2[2000050],res2[2000050];
//
inline void refresh2(int now){
	t2[now]=min(t2[now<<1],t2[now<<1|1]);
}
void build2(int l,int r,int now){
	if(l==r){
		t2[now]=a2[l];
		return;
	}
	int mid=(l+r)>>1;
	build2(l,mid,now<<1);
	build2(mid+1,r,now<<1|1);
	refresh2(now);
}
void pushdown2(int l,int r,int now){
	if(l==r){
		tag2[now]=0;
		return;
	}
	tag2[now<<1]+=tag2[now];
	tag2[now<<1|1]+=tag2[now];
	int mid=(l+r)>>1;
	t2[now<<1]+=tag2[now];
	t2[now<<1|1]+=tag2[now];
	tag2[now]=0;
}
void add2(int l,int r,int now,int LL,int RR,int data){
	if(LL<=l&&r<=RR){
		t2[now]+=data;
		tag2[now]+=data;
		return;
	}
	if(tag2[now]) pushdown2(l,r,now);
	int mid=(l+r)>>1;
	if(LL<=mid) add2(l,mid,now<<1,LL,RR,data);
	if(mid<RR) add2(mid+1,r,now<<1|1,LL,RR,data);
	refresh2(now);
}
int query2(int l,int r,int now,int LL,int RR){
	if(LL<=l&&r<=RR){
		return t2[now];
	}
	if(tag2[now]) pushdown2(l,r,now);
	int mid=(l+r)>>1;int ans=1e9;
	if(LL<=mid) ans=min(query2(l,mid,now<<1,LL,RR),ans);
	if(mid<RR) ans=min(ans,query2(mid+1,r,now<<1|1,LL,RR));
	refresh2(now);
	return ans;
}

int x,y;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
		v[b[i]].push_back(i);
		add(1,n,1,i,n,1);
		add2(1,n,1,i,n,1);
		b[i]=1;
	}
	for(i=1;i<=200000;i++){
		if(v[i].size()==0){continue;}
		for(auto j:v[i]){
			x=(j>1)?query2(1,n,1,1,j-1):0;
			x=min(x,0);
			y=query(1,n,1,j,n);
			res[j]=max(res[j],(y-x+1-b[j])/2);
		}
		
		for(auto j:v[i]){
			b[j]=-1;
			add(1,n,1,j,n,-2);
			add2(1,n,1,j,n,-2);
		}
		
		for(auto j:v[i]){
			x=(j>1)?query(1,n,1,1,j-1):0;
			x=max(x,0);
			y=query2(1,n,1,j,n);
			res[j]=max(res[j],-(y-x-b[j])/2);
		}
		
	}
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}