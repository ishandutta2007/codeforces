#include <cstdio>
#include <algorithm>
#define int long long

int n,q,a[100001],b[100001];
struct info{
	long long sum,mn,mx;
}se[1000001];
info operator+(info a,info b){
	return (info){a.sum+b.sum,std::min(a.mn,b.mn+a.sum),std::max(a.mx,b.mx+a.sum)};
}
void build(int root,int l,int r){
	if(l==r){
		se[root]=(info){1ll*a[l],std::min(0ll,1ll*a[l]),std::max(0ll,1ll*a[l])};
	// printf("%lld %lld %lld %lld %lld\n",l,r,se[root].sum,se[root].mn,se[root].mx);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=se[root<<1]+se[root<<1|1];
	// printf("%lld %lld %lld %lld %lld\n",l,r,se[root].sum,se[root].mn,se[root].mx);
}
info query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return (info){0,0,0};
	if(el<=l&&er>=r)return se[root];
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
signed main(){
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	for(int i=1;i<=n;++i)scanf("%lld",b+i),a[i]=b[i]-a[i];
	build(1,1,n);
	for(int i=1,l,r;i<=q;++i){
		scanf("%lld%lld",&l,&r);
		info now=query(1,1,n,l,r);
		// printf("%lld %lld %lld\n",now.sum,now.mn,now.mx);
		if(now.sum!=0||now.mn<0)puts("-1");
		else printf("%lld\n",now.mx);
	}
}