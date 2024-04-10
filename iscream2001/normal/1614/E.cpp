#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
LL qpow(LL x,LL y,LL P){
	LL re=1;
	x=x%P;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

const int N=1e6+10;
const double eps=1e-6;
const LL sed=1e9+7;
const LL P=998244353;
const LL INF=2e18;
/*
LL fac[N+10],inv[N+10];
LL bin[70];

bool not_pri[N+10];
int cntp=0;
int pri[N];

void init(){
	bin[0]=1;
	for(int i=1;i<=60;++i){
		bin[i]=bin[i-1]<<1;
	}
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=N;++i){
		fac[i]=fac[i-1]*i%P;
	}
	inv[N]=qpow(fac[N],P-2,P);
	for(LL i=N;i>1;--i){
		inv[i-1]=inv[i]*i%P;
	}
	for(int i=2;i<=N;++i){
		if(!not_pri[i]){
			pri[++cntp]=i;
		}
		for(int j=1;j<=cntp&&i*pri[j]<=N;++j){
			not_pri[i*pri[j]]=1;
			if(i%pri[j]==0){
				break;
			}
		}
	}
	return;
}
*/
set<int> S;
set<int>::iterator it;

int n,m;
LL a[N];

int seg=0;

struct LazyTag{
	int x;
};

struct Segment{
	int ls,rs;
	//Val
	int vl,vr;
	//LazyTag 
	int ad;
}d[20000000];

void clr(int id,int l,int r){
	d[id].ls=d[id].rs=0;
	//
	d[id].vl=l;d[id].vr=r;d[id].ad=0;
	return;
}

bool Cut(int id){
	//
	return 0;
}

bool Check(int id){
	//
	return 1;
}

void PutTag(int id,LazyTag K){
	//
	d[id].vl+=K.x;
	d[id].vr+=K.x;
	d[id].ad+=K.x;
	return;
}

void pushup(int id){
	//
	d[id].vl=d[d[id].ls].vl;
	d[id].vr=d[d[id].rs].vr;
	return;
}

void pushdown(int id){
	//
	LazyTag K=(LazyTag){d[id].ad};d[id].ad=0;
	PutTag(d[id].ls,K);
	PutTag(d[id].rs,K);
	return;
}



void Change(int id,int l,int r,int ql,int qr,LazyTag K){
	
	if(ql>r||qr<l||Cut(id)) return;
	if(ql<=l&&qr>=r&&Check(id)){
		PutTag(id,K);
		return;
	}
	int mid=(l+r)>>1;
	if(!d[id].ls){
		d[id].ls=++seg;
		clr(seg,l,mid);
	}
	if(!d[id].rs){
		d[id].rs=++seg;
		clr(seg,mid+1,r);
	}
	
	pushdown(id);
	Change(d[id].ls,l,mid,ql,qr,K);
	Change(d[id].rs,mid+1,r,ql,qr,K);
	pushup(id);
	return;
} 
int rrr;
void ask(int id,int l,int r,int K){
	if(d[id].vl>K) return;
	if(d[id].vr<=K) {
		rrr=max(rrr,r);
		return;
	}
	
	int mid=(l+r)>>1;
	if(!d[id].ls){
		d[id].ls=++seg;
		clr(seg,l,mid);
	}
	if(!d[id].rs){
		d[id].rs=++seg;
		clr(seg,mid+1,r);
	}
	
	pushdown(id);
	ask(d[id].ls,l,mid,K);
	ask(d[id].rs,mid+1,r,K);
	pushup(id);
	return;
} 

int hhh(int id,int l,int r,int K){
	if(l==r) return d[id].vl;
	int mid=(l+r)>>1;
	if(!d[id].ls){
		d[id].ls=++seg;
		clr(seg,l,mid);
	}
	if(!d[id].rs){
		d[id].rs=++seg;
		clr(seg,mid+1,r);
	}
	
	pushdown(id);
	if(K<=mid) return hhh(d[id].ls,l,mid,K);
	else return hhh(d[id].rs,mid+1,r,K);
} 
void MAIN(){
	int op,x,y;
	LL z;
	scanf("%d",&m);
	seg=1;
	clr(seg,0,1000000000);
	int lastans=0; 
	while(m--){
		scanf("%d",&x);
		if(x>0){
			rrr=-1;
			ask(1,0,1000000000,x-1);
			if(rrr>=0){
				Change(1,0,1000000000,0,rrr,(LazyTag){1});
			}
		}
		if(x<1000000000){
			rrr=-1;
			ask(1,0,1000000000,x);
			if(rrr<1000000000){
				Change(1,0,1000000000,rrr+1,1000000000,(LazyTag){-1});
			}
		}
		scanf("%d",&op);
		while(op--){
			scanf("%d",&x);
			x=x+lastans;
			if(x>=1000000001) x-=1000000001;
			lastans=hhh(1,0,1000000000,x);
			printf("%d\n",lastans);
		}
	}
	return;
}
int main(){
	//init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}