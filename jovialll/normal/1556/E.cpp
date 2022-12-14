#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define int long long
struct sgt{
	struct val{
		int lmx,rmx,mx,sum;
	}s[N],ret;
	val merge(val aa,val bb){
		ret.sum=aa.sum+bb.sum;
		ret.lmx=max(aa.lmx,aa.sum+bb.lmx);
		ret.rmx=max(aa.rmx+bb.sum,bb.rmx);
		ret.mx=max(max(aa.mx,bb.mx),aa.rmx+bb.lmx);
		return ret;
	}
	int a[N];
	void build(int k,int l,int r){
		if(l==r){
			s[k].sum=a[l];
			s[k].mx=s[k].lmx=s[k].rmx=max(a[l],0ll);
			return ;
		}
		build(ls,l,mid);build(rs,mid+1,r);
		s[k]=merge(s[ls],s[rs]);
	}
	val query(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			return s[k];
		}
		if(x>mid)return query(rs,mid+1,r,x,y);
		if(y<=mid)return query(ls,l,mid,x,y);
		return merge(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
	}
}f1,f2;
long long s[N],g[N<<2];
int n,m,i,l,r;
void build(int k,int l,int r){
	if(l==r)g[k]=s[l];
	else build(ls,l,mid),build(rs,mid+1,r),g[k]=min(g[ls],g[rs]);
}
int MX(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return g[k];
	if(x>r||y<l)return 1e18;
	return min(MX(ls,l,mid,x,y),MX(rs,mid+1,r,x,y));
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>f1.a[i];
	}
	for(i=1;i<=n;++i)cin>>f2.a[i],f2.a[i]-=f1.a[i],f1.a[i]=-f2.a[i];
	for(i=1;i<=n;++i)s[i]=s[i-1]+f2.a[i];
	f1.build(1,1,n);
	f2.build(1,1,n);
	build(1,1,n);
	while(m--){
		cin>>l>>r;
		if(s[r]!=s[l-1]||MX(1,1,n,l-1,r)!=s[l-1]){cout<<-1<<"\n";continue;}
		cout<<max(f1.query(1,1,n,l,r).mx,f2.query(1,1,n,l,r).mx)<<"\n";
	}
}