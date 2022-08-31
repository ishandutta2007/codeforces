#include <bits/stdc++.h>
#define int long long

std::map<int,int>map;
int n,k,d,a[200001],b[200001],nxt[200001];
int L=1,R=1;
int mn[200001],mx[200001];
void upd(int l,int r){if(r-l>R-L||(r-l==R-L&&l<L))L=l,R=r;}
struct point{
	int v,l,r,o;
};
bool cmp(point a,point b){
	return a.v>b.v||(a.v==b.v&&a.o<b.o);
}
int se[2000001];
void update(int root,int l,int r,int e,int x){
	if(l==r){
		se[root]=x;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=std::max(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return std::max(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
struct DS{
	std::vector<point>vec;
	void solve(){
		std::sort(vec.begin(),vec.end(),cmp);
//		puts("solve");
//		for(int i=0;i<(int)vec.size();i++)
//			printf("%d %d %d %d\n",vec[i].v,vec[i].l,vec[i].r,vec[i].o);
		for(int i=0;i<(int)vec.size();i++)
			if(vec[i].o==-1)update(1,1,n,vec[i].l,vec[i].l);
			else if(vec[i].l<=vec[i].r)upd(vec[i].o,query(1,1,n,vec[i].l,vec[i].r));
		for(int i=0;i<(int)vec.size();i++)
			if(vec[i].o==-1)update(1,1,n,vec[i].l,0);
		vec.clear();
	}
	void add(int v,int l,int r,int o){
		vec.push_back((point){v,l,r,o});
	}
}A,B,C;
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	int T=r;
	for(int i=mid+1;i<=r;i++){
		if(i>mid+1)mn[i]=std::min(mn[i-1],b[i]),mx[i]=std::max(mx[i-1],b[i]);
		else mn[i]=mx[i]=b[i];
		T=std::min(T,nxt[i]-1);
		A.add(mn[i]+i,i,i,-1);
		B.add(i-mx[i],i,i,-1);
		C.add(i-mx[i]+mn[i],i,i,-1);
	}
	for(int i=mid;i>=l;i--){
		if(i<mid)mn[i]=std::min(mn[i+1],b[i]),mx[i]=std::max(mx[i+1],b[i]);
		else mn[i]=mx[i]=b[i];
	}
//	printf("solve %d %d %d\n",l,r,mid);
//	for(int i=l;i<=r;i++)printf("%d %d\n",mn[i],mx[i]);
	for(int i=mid,R=T,x1=mid+1,x2=mid+1;i>=l;i--){
		R=std::min(R,nxt[i]-1);
		if(R<=mid)break;
		while(x1<=r&&mn[x1]>=mn[i])++x1;
		while(x2<=r&&mx[x2]<=mx[i])++x2;
		int x=std::min(std::min(x1-1,x2-1),R);
		if(x>mid&&mx[i]-mn[i]+i-x<=k)upd(i,x);
		if(x1<x2&&x1<=R)A.add(mx[i]+i-k,x1,std::min(x2-1,R),i);
		if(x2<x1&&x2<=R)B.add(i-mn[i]-k,x2,std::min(x1-1,R),i);
		if(std::max(x1,x2)<=R)C.add(i-k,std::max(x1,x2),R,i);
	}
//	if(18>=l&&18<=mid&&45>mid&&45<=r)printf("%d %d %d %d\n",mn[18],mx[18],mn[45],mx[45]); 
	A.solve();
	B.solve();
	C.solve();
	solve(l,mid);
	solve(mid+1,r);
}
signed main(){
	scanf("%lld%lld%lld",&n,&k,&d);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]+=1000000000;
	if(!d){
		for(int i=1,last=1;i<=n;i++){
			if(a[i]!=a[i-1])last=i;
			upd(last,i);
		}
		printf("%lld %lld\n",L,R);
		return 0;
	}
	for(int i=1;i<=n;i++)b[i]=a[i]/d;
	for(int i=n;i;i--){
		nxt[i]=map.count(b[i])?map[b[i]]:0x7f7f7f7f;
		map[b[i]]=i;
	}
	for(int i=2,last=1;i<=n+1;i++){
		if(i==n+1||a[i]%d!=a[i-1]%d){
			solve(last,i-1);
			last=i;
		}
	}
	printf("%lld %lld\n",L,R);
}