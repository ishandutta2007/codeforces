#include<cstdio>
#include<algorithm>
#include<vector>
#include<tr1/unordered_map>
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<pii> vec[1210000];
tr1::unordered_map<ll,int> mp;
int n,x,y,cnt;
pii a[1210000];
int sx[1210000],sy[1210000],fa[1210000];
ll Ans[1210000],ans[1210000];
int findset(int x){
	while (fa[x]) x=fa[x];
	return x;
}

void change(int now,int l,int r,int x,int y,pii v){
	if (l==x&&r==y){
		vec[now].push_back(v);
		return;
	}
	int mid=(l+r)>>1;
	if (y<=mid) change(now<<1,l,mid,x,y,v);
	else if (x>mid) change(now<<1|1,mid+1,r,x,y,v);
	else change(now<<1,l,mid,x,mid,v),change(now<<1|1,mid+1,r,mid+1,y,v);
}

void solve(int now,int l,int r){
	Ans[now]=Ans[now>>1];
	int c=cnt,sz=(int)vec[now].size();
	for (int i=0;i<sz;i++){
		int x=vec[now][i].first,y=vec[now][i].second+300005;
		x=findset(x); y=findset(y);
		if (x==y) continue;
		if (sx[x]+sy[x]>sx[y]+sy[y]) swap(x,y);
		Ans[now]-=sx[x]*sy[x]+sx[y]*sy[y];
		fa[x]=y;
		sx[y]+=sx[x]; sy[y]+=sy[x];
		Ans[now]+=sx[y]*sy[y];
		a[++cnt]=pii(x,y);
	}
	if (l!=r){
		int mid=(l+r)>>1;
		solve(now<<1,l,mid);
		solve(now<<1|1,mid+1,r);
	} else ans[l]=Ans[now];
	for (;cnt>c;cnt--){
		int x=a[cnt].first,y=a[cnt].second;
		fa[x]=0; sx[y]-=sx[x]; sy[y]-=sy[x];
	}
}
ll k;
inline ll hs(int x,int y){
	return (x-1)*300000ll+y;
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&x,&y); k=hs(x,y);
		a[i]=pii(x,y);
		if (mp[k]){
			change(1,1,n,mp[k],i-1,a[i]);
			mp[k]=0;
		} else mp[k]=i;
	}
	for (int i=1;i<=n;i++){
		k=hs(a[i].first,a[i].second);
		if (mp[k]){
			change(1,1,n,mp[k],n,a[i]);
			mp[k]=0;
		}
	}
	for (int i=1;i<=n;i++) fa[i]=0,sx[i]=1;
	for (int i=1;i<=n;i++) fa[i+300005]=0,sy[i+300005]=1;
	cnt=0; solve(1,1,n);
	for (int i=1;i<n;i++) printf("%lld ",ans[i]);
	printf("%lld\n",ans[n]);
	return 0;
}