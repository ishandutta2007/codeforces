#include <algorithm>
#include <cstdio>
#include <set>
using std::max;

std::set<int>exi;
int n,q,a[200001],dir[200001],orig[200001];
struct segtree{
	int se[1000001];
	void update(int root,int l,int r,int el,int er,int x){
		if(el>r||er<l)return;
		if(el<=l&&er>=r)return (void)(se[root]=max(se[root],x));
		update(root<<1,l,(l+r)>>1,el,er,x);
		update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	}
	int query(int root,int l,int r,int e){
		if(l==r)return se[root];
		return max(se[root],((l+r)>>1>=e)?query(root<<1,l,(l+r)>>1,e):query(root<<1|1,((l+r)>>1)+1,r,e));
	}
}U,L;
char get(){
	char ch=getchar();
	while(ch!='U'&&ch!='L')ch=getchar();
	return ch;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		scanf("%d",a+i);
		orig[i]=a[i];
		dir[i]=get()=='U';
	}
	std::sort(orig+1,orig+q+1);
	int lim=std::unique(orig+1,orig+q+1)-orig-1;
	for(int i=1;i<=q;i++)a[i]=std::lower_bound(orig+1,orig+lim+1,a[i])-orig;
	for(int i=1;i<=q;i++){
		if(exi.count(a[i]))printf("0\n");
		else{
			if(dir[i]){
				int tem=L.query(1,1,lim,a[i]);
				U.update(1,1,lim,a[i],std::lower_bound(orig+1,orig+lim+1,n+1-tem)-orig,a[i]);
				printf("%d\n",(n+1-orig[a[i]])-tem);
			}
			else{
				int tem=U.query(1,1,lim,a[i]);
				L.update(1,1,lim,tem,a[i],(n+1)-orig[a[i]]);
				printf("%d\n",orig[a[i]]-orig[tem]);
			}
			exi.insert(a[i]);
		}
	}
}