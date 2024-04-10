//max - min + i >= r  
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=3e5+10;
const double eps=1e-6;

int n;
int a[N];


int rx,rn;
int Qx[N],Qn[N];

struct Seg{
	int l,r;
	int mn,sum,laz;
}d[N<<2];

#define ls id<<1
#define rs id<<1|1

void update(int id){
	if(d[id].l==d[id].r) return;
	if(d[ls].mn<d[rs].mn){
		d[id].mn=d[ls].mn;
		d[id].sum=d[ls].sum;
		return;
	}
	else if(d[ls].mn>d[rs].mn){
		d[id].mn=d[rs].mn;
		d[id].sum=d[rs].sum;
		return;
	}
	else{
		d[id].mn=d[ls].mn;
		d[id].sum=d[ls].sum+d[rs].sum;
	}
	return;
}

void build(int l,int r,int id){
	d[id].l=l;d[id].r=r;d[id].laz=0;
	if(l==r){
		d[id].mn=l;
		d[id].sum=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	update(id);
	return;
}

void pushdown(int id){
	if(d[id].l==d[id].r) return;
	if(d[id].laz!=0){
		d[ls].laz+=d[id].laz;
		d[ls].mn+=d[id].laz;
		d[rs].laz+=d[id].laz;
		d[rs].mn+=d[id].laz;
		d[id].laz=0;
	}
	return;
}

void add(int l,int r,int id,int w){
	pushdown(id);
	if(l==d[id].l&&r==d[id].r){
		d[id].laz+=w;
		d[id].mn+=w;
		return;
	}
	if(d[ls].r>=r) add(l,r,ls,w);
	else if(d[rs].l<=l) add(l,r,rs,w);
	else{
		add(l,d[ls].r,ls,w);
		add(d[rs].l,r,rs,w);
	}
	update(id);
	return;
}

int X,num;

void ask(int r,int id){
	pushdown(id);
	if(d[id].r<=r){
		if(d[id].mn<X){
			X=d[id].mn;
			num=0;
		}
		if(d[id].mn==X){
			num+=d[id].sum;
		}
		return;
	}
	ask(r,ls);
	if(d[rs].l<=r) ask(r,rs);
	return;
}


void MAIN(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&u,&v);
		a[u]=v;
	}
	build(1,n,1);
	rx=0;rn=0;
	long long ans=0;
	for(int i=1;i<=n;++i){
		while(rx>0&&a[i]>a[Qx[rx]]){
			//cout<<Qx[rx-1]+1<<" "<<Qx[rx]<<" "<<-a[Qx[rx]]<<endl;
			add(Qx[rx-1]+1,Qx[rx],1,-a[Qx[rx]]);
			--rx;
		}
		Qx[++rx]=i;
		add(Qx[rx-1]+1,Qx[rx],1,a[Qx[rx]]);
		while(rn>0&&a[i]<a[Qn[rn]]){
			add(Qn[rn-1]+1,Qn[rn],1,a[Qn[rn]]);
			--rn;
		}
		Qn[++rn]=i;
		add(Qn[rn-1]+1,Qn[rn],1,-a[Qn[rn]]);
		//for(int j=1;j<=rn;++j) cout<<Qn[j]<<" ";puts("");
		X=100000000;num=0;
		ask(i,1);
		//cout<<"mow "<<X<<" "<<num<<endl;
		if(X==i) ans+=num;
	} 
	printf("%lld\n",ans);
	return;
}
int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}