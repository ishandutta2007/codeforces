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
int n;
int a[100005];
struct segtree{
	int n,n2;
	int val[400005],memo[400005];
	void init(int n_,int rank){
		n=1;
		n2=n_;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0;
		memset(memo,0,sizeof(memo));
		REP(i,n_) if(a[i]>>rank&1) val[i+n-1]=1;
		for(int i=n-2;i>=0;--i) val[i]=val[i*2+1]+val[i*2+2];
	}
	void renew(int i,int l,int r){
		memo[i]^=1;
		val[i]=min(r,n2)-min(n2,l)-val[i];
	}
	void flip(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			renew(i,l,r);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		if(memo[i]){
			renew(i*2+1,l,md);renew(i*2+2,md,r);
			memo[i]=0;
		}
		flip(a,b,i*2+1,l,md);
		flip(a,b,i*2+2,md,r);
		val[i]=val[i*2+1]+val[i*2+2];
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			return val[i];
		}
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		if(memo[i]){
			renew(i*2+1,l,md);renew(i*2+2,md,r);
			memo[i]=0;
		}
		return query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r);
	}
};
segtree seg[25];

int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,22) seg[i].init(n,i);
	int m;cin>>m;
	REP(hoge,m){
		int t,l,r;cin>>t>>l>>r;--l;
		if(t==1){
			lint res=0;
			REP(i,22) res+=seg[i].query(l,r,0,0,seg[i].n)*(1ll<<i);
			cout<<res<<endl;
		}else{
			int x;cin>>x;
			REP(i,22) if(x>>i&1){
				seg[i].flip(l,r,0,0,seg[i].n);
			}
		}
	}


	return 0;
}