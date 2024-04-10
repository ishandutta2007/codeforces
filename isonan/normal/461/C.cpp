#include <cstdio>

int start=0,IsRev=0,length,a[100001],q,se[400001],n;
int getpos(int x){return (!IsRev)?start+x:start+(length-x+1);}
void build(int root,int l,int r,int el,int er){
	if(el>er)el^=er^=el^=er;
	if(l==r){
		se[root]=a[l];
		return;
	}
	if(el>r||er<l)return;
	build(root<<1,l,(l+r)>>1,el,er);
	build(root<<1|1,((l+r)>>1)+1,r,el,er);
	se[root]=se[root<<1]+se[root<<1|1];
}
int query(int root,int l,int r,int el,int er){
	if(el>er)el^=er^=el^=er;
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
int main(){
	scanf("%d%d",&length,&q);
	n=length;
	for(int i=1;i<=length;i++)a[i]=1;
	build(1,1,n,1,length);
	for(int i=1,opt,l,r;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&l);
			if(l>length-l)l=length-l,IsRev^=1;
			length-=l;
			if(IsRev){
				for(int i=1;i<=l;i++)a[getpos(i)]+=a[getpos(i)+(i<<1)-1];
				build(1,1,n,getpos(l),getpos(1));
			}
			else{
				start+=l;
				for(int i=1;i<=l;i++)a[getpos(i)]+=a[getpos(i)-(i<<1)+1];
				build(1,1,n,getpos(1),getpos(l));
			}
		}
		else{
			scanf("%d%d",&l,&r);
			++l;
			printf("%d\n",query(1,1,n,getpos(l),getpos(r)));
		}
//		for(int i=1;i<=length;i++)printf("%d ",a[getpos(i)]);putchar('\n');
	}
}