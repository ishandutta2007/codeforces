#include <cstdio>

struct segtree{
	int pos[900001];
	double val[200001];
	bool flag;
	void build(int root,int l,int r){
		if(l==r){pos[root]=l;return;}
		build(root<<1,l,(l+r)>>1);
		build(root<<1|1,((l+r)>>1)+1,r);
		pos[root]=((val[pos[root<<1]]>val[pos[root<<1|1]])^flag)?pos[root<<1]:pos[root<<1|1];
	}
	void update(int root,int l,int r,int e){
		if(l==r){pos[root]=l;return;}
		if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
		else update(root<<1|1,((l+r)>>1)+1,r,e);
		pos[root]=((val[pos[root<<1]]>val[pos[root<<1|1]])^flag)?pos[root<<1]:pos[root<<1|1];
	}
}Tadd,Tdel;
int a[200001],n,t,q,chosen[200001];
double p[200001],ans,tot[200001];
double calc(double a,double r){
	return a/(a+r)-(a-1.)/(a+r-1.);
}
void add(int tem){
//	printf("add %d\n",tem);
	ans+=Tadd.val[tem];
	tot[tem]+=Tadd.val[tem];
	Tdel.val[tem]=Tadd.val[tem];
	if((++chosen[tem])==a[tem])Tadd.val[tem]=-1.;
	else Tadd.val[tem]=p[tem]*calc(chosen[tem]+1,a[tem]);
	Tadd.update(1,1,n,tem);
	Tdel.update(1,1,n,tem);
}
void del(int tem){
	ans-=Tdel.val[tem];
	tot[tem]-=Tdel.val[tem];
	Tadd.val[tem]=Tdel.val[tem];
	if(!(--chosen[tem]))Tdel.val[tem]=10000000.;
	else Tdel.val[tem]=p[tem]*calc(chosen[tem],a[tem]);
	Tadd.update(1,1,n,tem);
	Tdel.update(1,1,n,tem);
}
int main(){
	scanf("%d%d%d",&n,&t,&q);
	Tadd.flag=0,Tdel.flag=1;
	for(int i=1;i<=n;i++)scanf("%lf",p+i);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)Tadd.val[i]=p[i]*(1./((double)a[i]+1.));
	Tadd.build(1,1,n);
	for(int i=1;t;i++){
		int tem=Tadd.pos[1];
		if(Tadd.val[tem]==-1.)break;
		--t;
		ans+=Tadd.val[tem];
		tot[tem]+=Tadd.val[tem];
		if(++chosen[tem]==a[tem])Tadd.val[tem]=-1.;
		else Tadd.val[tem]=p[tem]*calc(chosen[tem]+1,a[tem]);
		Tadd.update(1,1,n,tem);
	}
	for(int i=1;i<=n;i++){
		if(chosen[i])Tdel.val[i]=p[i]*calc(chosen[i],a[i]);
		else Tdel.val[i]=10000000.;
	}
	Tdel.build(1,1,n);
//	printf("%lf %d\n",ans,t);
	for(int i=1,opt,r;i<=q;i++){
		scanf("%d%d",&opt,&r);
		if(opt==1){
			++a[r];
			if(chosen[r]){
				--chosen[r];
				++t;
			}
			ans-=tot[r];
			tot[r]=p[r]*((double)chosen[r])/((double)chosen[r]+(double)a[r]);
			ans+=tot[r];
//			printf("%lf\n",ans);
//			printf("%d %lf %d\n",Tadd.pos[1],Tadd.val[Tadd.pos[1]],t);
			Tadd.val[r]=chosen[r]==a[r]?-1.:p[r]*calc(chosen[r]+1,a[r]);
//			printf("%lf %lf %lf %lf %d %d\n",ans,Tadd.val[Tadd.pos[1]],Tdel.val[Tdel.pos[1]],Tadd.val[1],chosen[r],a[r]);
			Tdel.val[r]=chosen[r]?p[r]*calc(chosen[r],a[r]):10000000.;
			Tadd.update(1,1,n,r);
			Tdel.update(1,1,n,r);
			while(t&&Tadd.val[Tadd.pos[1]]!=-1.)add(Tadd.pos[1]),--t;
			while(Tadd.val[Tadd.pos[1]]>Tdel.val[Tdel.pos[1]]){
				int tem=Tdel.pos[1];
				add(Tadd.pos[1]);
				del(tem);
			}
		}
		else{
			--a[r];
			if(chosen[r]>a[r]){
				--chosen[r];
				++t;
			}
			ans-=tot[r];
			tot[r]=p[r]*((double)chosen[r])/((double)chosen[r]+(double)a[r]);
			ans+=tot[r];
//			printf("%lf %lf %lf %lf %d\n",ans,Tadd.val[Tadd.pos[1]],Tdel.val[Tdel.pos[1]],Tadd.val[1],chosen[1]);
			Tadd.val[r]=chosen[r]==a[r]?-1.:p[r]*calc(chosen[r]+1,a[r]);
			Tdel.val[r]=chosen[r]?p[r]*calc(chosen[r],a[r]):10000000.;
			Tadd.update(1,1,n,r);
			Tdel.update(1,1,n,r);
			while(t&&Tadd.val[Tadd.pos[1]]!=-1.)add(Tadd.pos[1]),--t;
			while(Tadd.val[Tadd.pos[1]]>Tdel.val[Tdel.pos[1]]){
//				printf("%lf %lf\n",Tadd.val[Tadd.pos[1]],Tdel.val[Tdel.pos[1]]);
				int tem=Tdel.pos[1];
				add(Tadd.pos[1]);
				del(tem);
			}
		}
//		printf("*%lf\n",Tdel.val[1]);
		printf("%.9lf\n",ans);
	}
}