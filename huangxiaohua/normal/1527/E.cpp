#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,cur[40050]; 
int nxt[40050],son[40050];

ll t[400050],tag[400050],a[400050],f[105][40050],res,res2;
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
	scanf("%d%d",&n,&m);m--;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(cur[k]){
			nxt[cur[k]]=i;
			son[i]=cur[k];
			res+=i-son[i];
		}
		cur[k]=i;
	}

	for(i=1;i<=m;i++){
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		memset(tag,0,sizeof(tag));
		for(j=1;j<=n;j++){
			add(1,n+1,1,j+1,j+1,f[i-1][j]);
		}
		for(j=1;j<=n;j++){
			if(nxt[j]){
				add(1,n+1,1,1,j,nxt[j]-j);
			}
			if(son[j]){
				add(1,n+1,1,1,son[j],son[j]-j);
			}
			f[i][j]=query(1,n+1,1,1,j);
		}
	}
	for(i=1;i<=n;i++){
		res2=max(res2,f[m][i]);
	}
	printf("%lld",res-res2);
}