#include <cstdio>
#include <algorithm>

struct tag{double sum,suf;}se[4000001];
double mn[400010],mx[400010],L[400010],V[400010];
int top,n,l,x[200001],y[200001],num[400010];
bool cmp(int a,int b){return V[a]<V[b];}
tag merge(tag a,tag b){return (tag){a.sum+b.sum,std::min(a.suf,a.sum+b.suf)};}
void build(int root,int l,int r){
	if(l==r){
		se[root]=(tag){mx[l],mx[l]};
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=merge(se[root<<1],se[root<<1|1]);
}
void update(int root,int l,int r,int e,double x){
	if(l==r){
		se[root]=(tag){x,x};
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=merge(se[root<<1],se[root<<1|1]);
}
tag query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return (tag){0,1e18};
	if(el<=l&&er>=r)return se[root];
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void calc(double l,double v){
	++top;
	L[top]=l;
	V[top]=v;
	mn[top]=-l/(v+2.);
	if(v)mx[top]=l/v;
	else mx[top]=(v+1)*(double)::l-l;
}
int main(){
	scanf("%d%d",&n,&l);
	double v;
	for(int i=1;i<=n;i++){
		scanf("%d%d%lf",x+i,y+i,&v);
		if(x[i]>y[i-1])calc((double)(x[i]-y[i-1]),0);
		calc((double)(y[i]-x[i]),v);
	}
	if(l>y[n])calc((double)(l-y[n]),0);
	build(1,1,top);
	for(int i=1;i<=top;i++)num[i]=i;
	std::sort(num+1,num+top+1,cmp);
	double ans=0.;
	for(int i=1;i<=top;i++){
		int pos=num[i];
		auto n1=query(1,1,top,1,pos-1),n2=query(1,1,top,pos,top);
		double x=std::max(mn[pos],mx[pos]-(n1.sum+n2.suf));
//		printf("%lf %lf\n",x+L[pos],V[pos]+1);
		ans+=(x+L[pos])/(V[pos]+1);
		update(1,1,top,pos,x);
	}
	printf("%.13lf",ans);
}