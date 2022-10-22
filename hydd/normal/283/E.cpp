#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
int n,k,l,r,a[110000]; long long ans;
int sum[410000],rev[410000];
vector<pii> vec[110000];
void pushdown(int now,int l,int r){
	int mid=(l+r)>>1;
	if (rev[now]){
		rev[now<<1]^=1; rev[now<<1|1]^=1;
		sum[now<<1]=(mid-l+1)-sum[now<<1];
		sum[now<<1|1]=(r-mid)-sum[now<<1|1];
		rev[now]=0;
	}
}
void change(int now,int l,int r,int x,int y){
	if (l>r||x>y) return;
	if (l==x&&r==y){
		sum[now]=(r-l+1)-sum[now];
		rev[now]^=1; return;
	}
	pushdown(now,l,r); int mid=(l+r)>>1;
	if (y<=mid) change(now<<1,l,mid,x,y);
	else if (x>mid) change(now<<1|1,mid+1,r,x,y);
	else { change(now<<1,l,mid,x,mid); change(now<<1|1,mid+1,r,mid+1,y);}
	sum[now]=sum[now<<1]+sum[now<<1|1];
}
int query(int now,int l,int r,int x,int y){
	if (l==x&&r==y) return sum[now];
	pushdown(now,l,r); int mid=(l+r)>>1;
	if (y<=mid) return query(now<<1,l,mid,x,y);
	else if (x>mid) return query(now<<1|1,mid+1,r,x,y);
	else return query(now<<1,l,mid,x,mid)+query(now<<1|1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=k;i++){
		scanf("%d%d",&l,&r);
		l=lower_bound(a+1,a+n+1,l)-a;
		r=upper_bound(a+1,a+n+1,r)-a-1;
		vec[l].push_back(pii(l,r));
		vec[r+1].push_back(pii(l,r));
	}
	for (int i=1;i<=n;i++){
		int sz=vec[i].size();
		for (int j=0;j<sz;j++) change(1,1,n,vec[i][j].first,vec[i][j].second);
		int tmp=0;
		if (i>1) tmp+=(i-1)-query(1,1,n,1,i-1);
		if (i<n) tmp+=query(1,1,n,i+1,n);
		ans+=1ll*tmp*(tmp-1)/2;
	}
	printf("%lld\n",1ll*n*(n-1)*(n-2)/6-ans);
	return 0;
}