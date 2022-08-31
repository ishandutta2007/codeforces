#include <cstdio>
#include <cstring>

int n,q,a[200001],sum[1000001];
struct base{
	int v[31];
	void clear(){
		memset(v,0,sizeof v);
	}
	void insert(int x){
		for(int i=30;x&&~i;--i)
			if(x&(1<<i)){
				if(v[i])x^=v[i];
				else return (void)(v[i]=x);
			}
	}
	int cnt(){
		int tot=0;
		for(int i=0;i<=30;i++)tot+=(v[i]!=0);
		return tot;
	}
}se[1000001],ans;
void pushup(int x){
	sum[x]=sum[x<<1]^sum[x<<1|1];
	se[x]=se[x<<1];
	for(int i=0;i<=30;i++)
		se[x].insert(se[x<<1|1].v[i]);
}
void build(int root,int l,int r){
	if(l==r){
		sum[root]=a[l];
		se[root].clear();
		se[root].insert(a[l]);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void update(int root,int l,int r,int e){
	if(l==r){
		sum[root]=a[l];
		se[root].clear();
		se[root].insert(a[l]);
		return;
	}
	if(((l+r)>>1)>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	pushup(root);
}
void query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		for(int i=0;i<=30;i++)
			ans.insert(se[root].v[i]);
		return;
	}
	query(root<<1,l,(l+r)>>1,el,er);
	query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
int gsum(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return sum[root];
	return gsum(root<<1,l,(l+r)>>1,el,er)^gsum(root<<1|1,((l+r)>>1)+1,r,el,er); 
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=n;i;i--)a[i]^=a[i-1];
	build(1,1,n);
	for(int i=1,opt,l,r,k;i<=q;i++){
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1){
			scanf("%d",&k);
			a[l]^=k;
			update(1,1,n,l);
			if(r<n){
				a[r+1]^=k;
				update(1,1,n,r+1);
			}
		}
		else{
			ans.clear();
			query(1,1,n,l+1,r);
			ans.insert(gsum(1,1,n,1,l));
			printf("%d\n",(1<<ans.cnt()));
		}
	}
}