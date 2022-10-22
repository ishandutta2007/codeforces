#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=2e9;
typedef pair<int,int> pii;
int n,m,l,r,mn,a[510000],Ans[510000];
int v[2100000];
set<int> s[2100000];
vector<pii> vec[510000];
void build(int now,int l,int r){
	s[now].insert(-INF); s[now].insert(INF);
	v[now]=INF;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(now<<1,l,mid); build(now<<1|1,mid+1,r);
}
void change(int now,int l,int r,int x){
	if (l>x) return;
	if (l==r){
		if (x!=l){
			v[now]=min(v[now],abs(a[x]-a[l]));
			mn=min(mn,v[now]);
		}
		return;
	}
	int mid=(l+r)>>1;
	int val=min(abs(a[x]-(*s[now].lower_bound(a[x]))),abs(a[x]-(*--s[now].lower_bound(a[x]))));
	if (val<mn){
		change(now<<1|1,mid+1,r,x);
		change(now<<1,l,mid,x);
		v[now]=min(v[now<<1],v[now<<1|1]);
	}
	mn=min(mn,v[now]);
}
void change2(int now,int l,int r,int x){
	if (l==r) return;
	int mid=(l+r)>>1; s[now].insert(a[x]);
	if (x<=mid) change2(now<<1,l,mid,x);
	else change2(now<<1|1,mid+1,r,x);
}
int query(int now,int l,int r,int x){
	if (l==x) return v[now];
	int mid=(l+r)>>1;
	if (x<=mid) return min(query(now<<1,l,mid,x),v[now<<1|1]);
	else return query(now<<1|1,mid+1,r,x);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		vec[r].push_back(pii(l,i));
	}
	build(1,1,n);
	for (int i=1;i<=n;i++){
		mn=INF; change(1,1,n,i);
		change2(1,1,n,i);
		int sz=vec[i].size();
		for (int j=0;j<sz;j++) Ans[vec[i][j].second]=query(1,1,n,vec[i][j].first);
	}
	for (int i=1;i<=m;i++) printf("%d\n",Ans[i]);	
	return 0;
}