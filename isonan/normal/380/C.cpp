#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;
using std::min;

struct point{
	int tot,left,right;
}num[5000001];
point merge(point a,point b){
	int tem=min(a.left,b.right);
	return (point){a.tot+b.tot+tem,b.left+a.left-tem,a.right+b.right-tem};
}
char str[1000001];
int n,Q;
void build(int root,int l,int r){
	if(l==r){
		if(str[l]=='(')num[root]=(point){0,1,0};
		else num[root]=(point){0,0,1};
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	num[root]=merge(num[root<<1],num[root<<1|1]);
}
point query(int root,int l,int r,int el,int er){
	if(el<=l&&er>=r)return num[root];
	int mid=(l+r)>>1;
	if(el>mid)return query(root<<1|1,((l+r)>>1)+1,r,el,er);
	else if(er<=mid)return query(root<<1,l,(l+r)>>1,el,er);
	else return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	build(1,1,n);
	scanf("%d",&Q);
	for(int i=1,l,r;i<=Q;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,1,n,l,r).tot<<1);
	}
}