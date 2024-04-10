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
typedef pair<lint,lint> pl;
lint fib[200005],fib01[200005],fib10[200005];
lint fibs[200005],fib01s[200005],fib10s[200005];
int n,m;
int ar[200005];
const lint mod=1000000000;

struct segtree{
	struct node{
		lint val,val01,val10;
		int all;
		int cnt;
		node(){
			val=val01=val10=all=cnt=0;
		}
	};
	void fix(node& a){
		a.val%=mod;
		a.val01%=mod;
		a.val10%=mod;
		a.all%=mod;
	}

	void merge(node& res,node& L,node& R){
		res.val=L.val+R.val10*fib[L.cnt]%mod+R.val01*fib[L.cnt+1]%mod;

		res.val01=L.val01+R.val10*fib01[L.cnt]%mod+R.val01*fib01[L.cnt+1]%mod;

		res.val10=L.val10+R.val10*fib10[L.cnt]%mod+R.val01*fib10[L.cnt+1]%mod;
		res.cnt=L.cnt+R.cnt;
		res.all=0;
		fix(res);
	}
	node val[800005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		memset(val,0,sizeof(val));

		REP(i,n_) val[i+n-1].cnt=1;
		for(int i=n-2;i>=0;--i) merge(val[i],val[i*2+1],val[i*2+2]);
	}
	void add_(node& a,int len,lint w){
		a.all+=w;
		a.val+=w*fibs[len];
		a.val10+=w*fib10s[len];
		a.val01+=w*fib01s[len];

		fix(a);
	}
	void push(int i,int l,int r){
		int md=(l+r)>>1;
		if(val[i].all){
			lint w=val[i].all;
			add_(val[i*2+1],md-l,w);
			add_(val[i*2+2],md-l,w);
			val[i].all=0;
		}
	}
	void set(int k,int i,int l,int r,int v){
		if(l==k && r-l==1){
			val[i].val=val[i].val10=v;
			val[i].val01=0;
			return;
		}
		if(k+1<=l || r<=k) return;
		int md=(l+r)>>1;
		push(i,l,r);
		set(k,i*2+1,l,md,v);
		set(k,i*2+2,md,r,v);
		merge(val[i],val[i*2+1],val[i*2+2]);
	}
	void add(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			add_(val[i],r-l,v);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		push(i,l,r);
		add(a,b,i*2+1,l,md,v);
		add(a,b,i*2+2,md,r,v);
		merge(val[i],val[i*2+1],val[i*2+2]);
	}

	node query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			return val[i];
		}
		if(b<=l || r<=a) return node();
		
		push(i,l,r);
		int md=(l+r)>>1;
		node L=query(a,b,i*2+1,l,md),R=query(a,b,i*2+2,md,r);
		node res;
		merge(res,L,R);
		return res;
	}
};
segtree seg;
		
int main(){
	fib[0]=1;fib[1]=1;
	fib01[0]=0;fib01[1]=1;
	fib10[0]=1;fib10[1]=0;

	fibs[1]=1;fibs[2]=2;
	fib01s[1]=0;fib01s[2]=1;
	fib10s[1]=1;fib10s[2]=1;
	REPN(i,200005,2){
		fib[i]=(fib[i-1]+fib[i-2])%mod;
		fib01[i]=(fib01[i-1]+fib01[i-2])%mod;
		fib10[i]=(fib10[i-1]+fib10[i-2])%mod;

		fibs[i+1]=(fibs[i]+fib[i])%mod;
		fib01s[i+1]=(fib01s[i]+fib01[i])%mod;
		fib10s[i+1]=(fib10s[i]+fib10[i])%mod;
	}



	cin>>n>>m;
	REP(i,n) cin>>ar[i];

	seg.init(n);
	REP(i,n){
		seg.set(i,0,0,seg.n,ar[i]);
	}

	REP(i,m){
		int t;scanf("%d",&t);
		if(t==1){
			int x,v;scanf("%d%d",&x,&v);
			--x;
			seg.set(x,0,0,seg.n,v);
		}else if(t==2){
			int l,r;scanf("%d%d",&l,&r);
			--l;
			
			lint res=seg.query(l,r,0,0,seg.n).val;
			cout<<res<<endl;
		}else{
			int l,r,d;scanf("%d%d%d",&l,&r,&d);
			--l;
			seg.add(l,r,0,0,seg.n,d);
		}
	}


	return 0;
}