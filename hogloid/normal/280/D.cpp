#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
struct segment{
	int l,r,val;
	segment(int l_=0,int r_=0,int val_=0){
		l=l_;r=r_;val=val_;
	}
	const segment& operator *=(const int a){
		val*=a;
	}
	segment operator +(const segment& a)const{
		segment res;
		res.l=l;
		res.r=a.r;
		res.val=val+a.val;

		return res;
	}
	const bool operator <(const segment& a)const{
		return val<a.val;
	}

};

struct node{
	int fail;
	int l,r;
	segment Lmin,Rmin,Lmax,Rmax,Amax,Amin,sum;
	int sign;
	node(int null=0){
		fail=null;
		sign=0;
	}

	void init(int a,int l_){
		l=l_;r=l+1;
		if(a>=0){
			Lmin=Rmin=Amin=segment(l,l,0);
			Lmax=Rmax=Amax=segment(l,l+1,a);
		}else{
			Lmin=Rmin=Amin=segment(l,l+1,a);
			Lmax=Rmax=Amax=segment(l,l,0);
		}
		sum=segment(l,l+1,a);
	}
	void ref(){
		swap(Lmin,Lmax);
		Lmin*=-1;Lmax*=-1;
		swap(Rmax,Rmin);
		Rmax*=-1;Rmin*=-1;

		swap(Amax,Amin);
		Amax*=-1;Amin*=-1;
		sum*=-1;

		sign^=1;
	}
};
const node null=node(1);
struct segtree{

	
	node merge(const node& a,const node& b){
		if(a.fail) return b;
		if(b.fail) return a;

		static node res;
		res.l=a.l;
		res.r=b.r;

		res.Lmin=min(a.Lmin,a.sum+b.Lmin);
		res.Rmin=min(b.Rmin,a.Rmin+b.sum);
		res.Lmax=max(a.Lmax,a.sum+b.Lmax);
		res.Rmax=max(b.Rmax,a.Rmax+b.sum);

		res.Amax=max(max(a.Amax,b.Amax),a.Rmax+b.Lmax);
		res.Amin=min(min(a.Amin,b.Amin),a.Rmin+b.Lmin);
		res.sum=a.sum+b.sum;
		
		return res;
	}
	int n;
	node val[400005];
	void init(int n_,int* ar){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n){
			val[i+n-1].init(ar[i],i);
		}
		for(int i=n-2;i>=0;--i) val[i]=merge(val[i*2+1],val[i*2+2]);
	}
	void push(int i){
		if(val[i].sign){
			val[i*2+1].ref();
			val[i*2+2].ref();
			val[i].sign=0;
		}
	}

	void set(int a,int i,int l,int r,int v){
		if(l==a && r==l+1){
			val[i].init(v,l);
			return;
		}
		if(a<l || r<=a) return;
		int md=(l+r)>>1;
		push(i);
		set(a,i*2+1,l,md,v);
		set(a,i*2+2,md,r,v);
		val[i]=merge(val[i*2+1],val[i*2+2]);
	}

	node query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			return val[i];
		}
		if(b<=l || r<=a) return null;
		int md=(l+r)>>1;
		push(i);
		return merge(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
	void reflect(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			val[i].ref();
			return ;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		push(i);

		reflect(a,b,i*2+1,l,md);
		reflect(a,b,i*2+2,md,r);

		val[i]=merge(val[i*2+1],val[i*2+2]);
	}
};

int n,m;
int ar[200005];

node tmp[30];

segtree seg;

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ar[i]);
	
	seg.init(n,ar);
	
	scanf("%d",&m);
	REP(hoge,m){
		int t;
		scanf("%d",&t);
		if(t==0){
			int i,val;scanf("%d%d",&i,&val);--i;
			ar[i]=val;
			seg.set(i,0,0,seg.n,val);
		}else{
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			--l;
			
			int cnt=0,res=0;
			node tmp2;
			REP(hoge2,k){
				tmp2=seg.query(l,r,0,0,seg.n);
				if(tmp2.Amax.val<=0) break;
				res+=tmp2.Amax.val;
				
				seg.reflect(tmp2.Amax.l,tmp2.Amax.r,0,0,seg.n);
				tmp[cnt++]=tmp2;
			}

			printf("%d\n",res);
			REP(i,cnt) seg.reflect(tmp[i].Amax.l,tmp[i].Amax.r,0,0,seg.n);
		}
	}
	return 0;
}