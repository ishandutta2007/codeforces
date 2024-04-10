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
lint C[10][10];
const lint mod=1000000007;
int ar[100005];
lint memo[6][400005];
	struct node{
		lint val[6];
		int l,r;
		bool disable;
		lint all;
		node(bool flag=false){
			if(flag) disable=true;
			else{
				memset(val,0,sizeof(val));
				all=-1;
				disable=false;
			}
		}
	};
struct segtree{
	node val[400005];
	inline node merge(const node& a,const node& b){
		if(a.disable) return b;
		if(b.disable) return a;
		int sz=a.r-a.l;
		node res;
		res.l=a.l;res.r=b.r;
		REP(i,6){
			res.val[i]=a.val[i];
			lint mul=1;
			REP(j,i+1){
				res.val[i]+=b.val[i-j]*C[i][j]%mod*mul%mod;
				mul*=sz;
				mul%=mod;
			}
			res.val[i]%=mod;
		}
		return res;
	}
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n){
			REP(j,6) val[i+n-1].val[j]=(i<n_?ar[i]:0);
			val[i+n-1].l=i;
			val[i+n-1].r=i+1;
		}
		for(int i=n-2;i>=0;--i) val[i]=merge(val[i*2+1],val[i*2+2]);
	}
	inline void push(int i){
		if(val[i].all!=-1){
			int len=val[i].r-val[i].l;len/=2;
			val[i*2+1].all=val[i*2+2].all=val[i].all;
			REP(j,6) val[i*2+1].val[j]=val[i*2+2].val[j]=memo[j][len]*val[i].all%mod;
			val[i].all=-1;
		}
	}

	inline node query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return node(true);
		int md=(l+r)>>1;
		push(i);
		return merge(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
	inline void set(int a,int b,int i,int l,int r,lint v){
		if(a<=l && r<=b){
			val[i].all=v;
			REP(j,6) val[i].val[j]=memo[j][r-l]*v%mod;
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		push(i);
		set(a,b,i*2+1,l,md,v);
		set(a,b,i*2+2,md,r,v);
		val[i]=merge(val[i*2+1],val[i*2+2]);
	}

};
segtree seg;
int n,m;
int mpow(int a,int k){
	lint res=1;
	REP(i,k) res*=a,res%=mod;
	return res;
}
int main(){
	REP(i,10){
		C[i][0]=1;
		REP(j,i) C[i][j+1]=C[i-1][j]+C[i-1][j+1];
	}
	REP(i,6){
		memo[i][0]=0;
		REP(j,400000){
			memo[i][j+1]=(memo[i][j]+mpow(j+1,i))%mod;
		}
	}


	scanf("%d%d",&n,&m);

	REP(i,n) scanf("%d",&ar[i]);

	seg.init(n);
	
	char tmp[10];
	REP(hoge,m){
		int l,r,x;scanf("%s%d%d%d",tmp,&l,&r,&x);
		--l;
		if(tmp[0]=='='){
			seg.set(l,r,0,0,seg.n,x);
		}else{
			node tmp=seg.query(l,r,0,0,seg.n);
			cout<<tmp.val[x]<<endl;
		}
	}

	return 0;
}