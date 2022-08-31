#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::vector<std::pair<int,int> > point;
point se[800001];
int n,m,p,a[150001],k,lazy[800001];
point merge(point a,point b){
	for(int i=0;i<b.size();i++){
		bool cando=0;
		for(int j=0;j<a.size();j++)
			if(a[j].second==b[i].second){
				a[j].first+=b[i].first;
				cando=1;
				break;
			}
		if(!cando)a.push_back(b[i]);
	}
	std::sort(a.begin(),a.end());
	std::reverse(a.begin(),a.end());
	int lim=std::min((int)a.size(),k);
	if(a.size()>lim)for(int i=0;i<lim;i++)a[i].first-=a[lim].first;
	a.resize(lim);
	return a;
}
void pushup(int root){se[root]=merge(se[root<<1],se[root<<1|1]);}
void build(int root,int l,int r){
	if(l==r){
		se[root].push_back(std::make_pair(1,a[l]));
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void pushdown(int root,int x,int l,int r){se[root].resize(1),se[root][0]=std::make_pair(r-l+1,x),lazy[root]=x;}
void spread(int root,int l,int r){
	if(l==r)return;
	if(lazy[root]){
		pushdown(root<<1,lazy[root],l,(l+r)>>1);
		pushdown(root<<1|1,lazy[root],((l+r)>>1)+1,r);
		lazy[root]=0;
	}
}
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x,l,r);
		return;
	}
	spread(root,l,r);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
point query(int root,int l,int r,int el,int er){
	spread(root,l,r);
	if(el>r||er<l)return point();
	if(el<=l&&er>=r)return se[root];
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	k=100/p;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	build(1,1,n);
	for(int i=1,opt,l,r,id;i<=m;i++){
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1){
			scanf("%d",&id);
			update(1,1,n,l,r,id);
		}
		else{
			point now=query(1,1,n,l,r);
			printf("%d ",now.size());
			for(int i=0;i<now.size();i++)
				printf("%d ",now[i].second);
			putchar('\n');
		}
	}
}