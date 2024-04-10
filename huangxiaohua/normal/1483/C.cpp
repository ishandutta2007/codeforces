#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxn 300500
int i,j,k,n,m,T,b[300500],mp[300500],d[300500],sb;
ll c[300500],dp[300500],sb2;
set<int> s;

ll a[maxn];
ll t[maxn*4],tag[maxn*4];
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
void add(int l,int r,int now,int LL,int RR,ll data){
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
ll query(int l,int r,int now,int LL,int RR){
	//printf("%d %d %d\n",l,r,now);
	if(LL<=l&&r<=RR){
		return t[now];
	}
	if(tag[now]) pushdown(l,r,now);
	int mid=(l+r)>>1;ll ans=-1e15;
	if(LL<=mid) ans=max(query(l,mid,now<<1,LL,RR),ans);
	if(mid<RR) ans=max(ans,query(mid+1,r,now<<1|1,LL,RR));
	refresh(now);
	return ans;
}

int main(){
	scanf("%d",&n);
	dp[0]=-1e15;
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
		mp[b[i]]=i;
		dp[i]=-1e15;
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	d[1]=0;
	s.insert(0);
	s.insert(mp[1]);
	for(i=2;i<=n;i++){
		auto sb=s.lower_bound(mp[i]);
		sb--;
		d[i]=*sb;
		s.insert(mp[i]);
		
		//printf("%d %d\n",i,d[i]);
	}
	for(i=1;i<=n;i++){
		//printf("d%d %d\n",i,d[b[i]]);
		sb=d[b[i]];
		if(!d[b[i]]){
			if(i>1){
				sb2=query(1,n,1,1,i-1);
			}
			else{
				sb2=0;
			}
			//puts("a");
			sb2=max(sb2,0ll);
			dp[i]=sb2+c[i];
			add(1,n,1,i,i,dp[i]);
		}
		else{
			sb2=query(1,n,1,sb,i-1);
			dp[i]=max(sb2+c[i],dp[sb]);
			add(1,n,1,i,i,dp[i]);
		}
		//printf("%d %d\n",i,dp[i]);
	}
	printf("%lld",dp[n]);
}