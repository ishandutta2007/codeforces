#include <cstdio>
#include <vector>
#include <set>

int c[300001],n,q,a[300001],ans[300001];
struct info{
	int mn,pos;
}se[3000001];
info merge(info a,info b){return a.mn<b.mn?a:b;}
void pushup(int root){
	se[root]=merge(se[root<<1],se[root<<1|1]);
}
void build(int root,int l,int r){
	if(l==r){
		se[root].mn=a[l]<=l?l-a[l]:0x7f7f7f7f;
		se[root].pos=l;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
int lazy[3000001];
void pushdown(int x,int y){
	lazy[x]+=y;
	se[x].mn-=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
info query(int root,int l,int r,int el,int er){
	spread(root);
	if(el>r||er<l)return (info){0x7f7f7f7f,0};
	if(el<=l&&er>=r)return se[root];
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void set(int root,int l,int r,int e){
	if(l==r){
		se[root]=(info){0x7f7f7f7f,0};
		return;
	}
	spread(root);
	if((l+r)>>1>=e){
		set(root<<1,l,(l+r)>>1,e);
		pushdown(root<<1|1,1);
	}
	else set(root<<1|1,((l+r)>>1)+1,r,e);
	pushup(root);
}
std::vector<std::pair<int,int> >que[300001];
void update(int ind){
	for(;ind<=n;ind+=ind&-ind)++c[ind];
}
int query(int ind){
	int tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
void add(int x){
	update(x);
	set(1,1,n,x);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1,l,r;i<=q;i++)scanf("%d%d",&l,&r),++l,r=n-r,que[l].push_back(std::make_pair(r,i));
	build(1,1,n);
	for(int i=n;i;i--){
		for(;;){
			info now=query(1,1,n,i,n);
//			printf("%d %d %d\n",i,now.mn,now.pos);
			if(now.mn==0){
				add(now.pos);
			}
			else break;
		}
		for(int j=0;j<que[i].size();j++)ans[que[i][j].second]=query(que[i][j].first);
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}