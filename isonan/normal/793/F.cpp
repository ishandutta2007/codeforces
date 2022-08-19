#include <cstdio>
#include <vector>

int n,m,q,l[100001],r[100001],x[100001],y[100001],ans[100001];
std::vector<int>line[100001],que[100001];
int se[1000001],lazy[1000001];
void pushdown(int x,int y){
	se[x]=std::max(se[x],y);
	lazy[x]=std::max(lazy[x],y);
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0x7f7f7f7f;
	if(el<=l&&er>=r)return se[root];
	spread(root);
	return std::min(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d",l+i,r+i),line[r[i]].push_back(l[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)scanf("%d%d",x+i,y+i),que[y[i]].push_back(i);
	for(int i=1;i<=n;++i){
		for(int j=0;j<line[i].size();++j){
			int L=line[i][j];
			update(1,1,n,L,i-1,L);
		}
		for(int j=0;j<que[i].size();++j){
			int L=x[que[i][j]];
			int l=L,r=i,mid,ans;
			while(l<=r){
				mid=(l+r)>>1;
				if(query(1,1,n,L,mid-1)>=L)ans=mid,l=mid+1;
				else r=mid-1;
			}
			::ans[que[i][j]]=ans;
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
}