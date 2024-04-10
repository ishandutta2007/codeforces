#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long ll;
int Q,mx[2][410000],sx[2][410000],tag[2][410000],cnt[2][410000]; ll sum[410000];
bool work(int now,int p,int v){
	if (v<=sx[p][now]) return false;
	if (v<mx[p][now]){
		sum[now]-=1ll*(mx[p][now]-v)*cnt[p][now];
		mx[p][now]=v; tag[p][now]=v;
	}
	return true;
}
void pushdown(int now){
	if (tag[0][now]!=INF){
		work(ls,0,tag[0][now]);
		work(rs,0,tag[0][now]);
		tag[0][now]=INF;
	}
	if (tag[1][now]!=INF){
		work(ls,1,tag[1][now]);
		work(rs,1,tag[1][now]);
		tag[1][now]=INF;
	}
}
void pushup(int now){
	sum[now]=sum[ls]+sum[rs];
	if (mx[0][ls]==mx[0][rs]){
		cnt[0][now]=cnt[0][ls]+cnt[0][rs];
		mx[0][now]=mx[0][ls]; sx[0][now]=max(sx[0][ls],sx[0][rs]);
	} else
		if (mx[0][ls]<mx[0][rs]){
			cnt[0][now]=cnt[0][rs];
			mx[0][now]=mx[0][rs]; sx[0][now]=max(mx[0][ls],sx[0][rs]);
		} else{
			cnt[0][now]=cnt[0][ls];
			mx[0][now]=mx[0][ls]; sx[0][now]=max(sx[0][ls],mx[0][rs]);
		}
	if (mx[1][ls]==mx[1][rs]){
		cnt[1][now]=cnt[1][ls]+cnt[1][rs];
		mx[1][now]=mx[1][ls]; sx[1][now]=max(sx[1][ls],sx[1][rs]);
	} else
		if (mx[1][ls]<mx[1][rs]){
			cnt[1][now]=cnt[1][rs];
			mx[1][now]=mx[1][rs]; sx[1][now]=max(mx[1][ls],sx[1][rs]);
		} else{
			cnt[1][now]=cnt[1][ls];
			mx[1][now]=mx[1][ls]; sx[1][now]=max(sx[1][ls],mx[1][rs]);
		}
}
void change(int now,int l,int r,int x,int y,int p,int v){
	if (v>mx[p][now]) return;
	if (l==r){
		mx[p][now]=v; sx[p][now]=-INF;
		if (mx[p^1][now]!=INF){
			sum[now]=mx[p][now]+mx[p^1][now];
			cnt[p][now]=1; cnt[p^1][now]=1;
		}
		return;
	}
	if (x<=l&&r<=y&&work(now,p,v)) return;
	int mid=(l+r)>>1; pushdown(now);
	if (x<=mid) change(ls,l,mid,x,y,p,v);
	if (y>mid) change(rs,mid+1,r,x,y,p,v);
	pushup(now);
}
ll query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y) return sum[now];
	int mid=(l+r)>>1; ll res=0; pushdown(now);
	if (x<=mid) res+=query(ls,l,mid,x,y);
	if (y>mid) res+=query(rs,mid+1,r,x,y);
	return res;
}
int main(){
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	memset(mx,0x3f,sizeof(mx));
	memset(sx,0x3f,sizeof(sx));
	memset(tag,0x3f,sizeof(tag));
	scanf("%d",&Q); int op,l,r,k;
	while (Q--){
		scanf("%d%d%d",&op,&l,&r); r--;
		if (op==1){
			scanf("%d",&k);
			change(1,1,100000,l,r,(k>0),abs(k));
		} else printf("%lld\n",query(1,1,100000,l,r));
	}
	return 0;
}