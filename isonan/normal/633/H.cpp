#include <cmath>
#include <cstdio>
#include <algorithm>

int n,m,a[30001],orig[30001],q;
struct matrix{
	unsigned num[3][3];
	matrix(){
		static int i,j;
		for(i=0;i<3;++i)
			for(j=0;j<3;++j)
				num[i][j]=(i==j);
	}
	matrix operator*(matrix a){
		static matrix c;
		static int i,j;
		for(i=0;i<3;++i)
			for(j=0;j<3;++j)
				c.num[i][j]=(num[i][0]*a.num[0][j]+num[i][1]*a.num[1][j]+num[i][2]*a.num[2][j])%m;
		return c;
	}
}M[30001],se[200001];
struct query{
	int l,r,ord;
}num[30001];
int pos[30001],ans[30001],cnt[30001],lim;
bool cmp(query a,query b){return pos[a.l]!=pos[b.l]?a.l<b.l:((pos[a.l]&1)^(a.r<b.r));}
void update(int root,int l,int r,int e){
	if(l==r){
		if(cnt[l])se[root]=M[l];
		else se[root]=matrix();
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=se[root<<1|1]*se[root<<1];
}
void add(int x){
	if(!(cnt[a[x]]++))update(1,1,lim,a[x]);
}
void del(int x){
	if(!(--cnt[a[x]]))update(1,1,lim,a[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		orig[i]=a[i];
	}
	std::sort(orig+1,orig+n+1);
	lim=std::unique(orig+1,orig+n+1)-orig-1;
	for(int i=1;i<=lim;i++){
		M[i].num[0][0]=1;
		M[i].num[0][1]=1;
		M[i].num[0][2]=0;
		M[i].num[1][0]=1;
		M[i].num[1][1]=0;
		M[i].num[1][2]=0;
		M[i].num[2][0]=orig[i]%m;
		M[i].num[2][1]=0;
		M[i].num[2][2]=1;
	}
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(orig+1,orig+lim+1,a[i])-orig;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&num[i].l,&num[i].r);
		num[i].ord=i;
	}
	int bl=(int)sqrt(n);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/bl+1;
	std::sort(num+1,num+q+1,cmp);
	for(int i=1,l=1,r=0;i<=q;i++){
		while(r<num[i].r)add(++r);
		while(l>num[i].l)add(--l);
		while(l<num[i].l)del(l++);
		while(r>num[i].r)del(r--);
		ans[num[i].ord]=se[1].num[2][0];
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}