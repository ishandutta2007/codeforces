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
int n,len,h,m;
int b[200005],ar[200005],val[200005];

struct segtree{
	int val[800005],lazy[800005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=lazy[i]=0;
	}
	void push(int i){
		if(lazy[i]){
			lazy[i*2+1]+=lazy[i];
			lazy[i*2+2]+=lazy[i];
			val[i*2+1]+=lazy[i];
			val[i*2+2]+=lazy[i];
			lazy[i]=0;
		}
	}

	void add(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			lazy[i]+=v;
			val[i]+=v;
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		push(i);
		add(a,b,i*2+1,l,md,v);
		add(a,b,i*2+2,md,r,v);
		val[i]=max(val[i*2+1],val[i*2+2]);
	}
	int query(){
		return val[0];
	}
};
segtree seg;
int main(){
	cin>>n>>len>>h;
	REP(i,len) cin>>b[i];
	REP(i,n) cin>>ar[i];
	m=len;

	sort(b,b+m,greater<int>());
	REP(i,m) b[i]=h-b[i];

	seg.init(m);
	REP(i,n) ar[i]=upper_bound(b,b+m,ar[i])-b;
	REP(i,m) seg.add(i,i+1,0,0,seg.n,m-i);
	int res=0;
	REP(i,m) seg.add(0,ar[i],0,0,seg.n,-1);
	if(seg.query()<=0) ++res;
	for(int i=m;i<n;++i){
		int ad=ar[i],ers=ar[i-m];
		seg.add(0,ad,0,0,seg.n,-1);
		seg.add(0,ers,0,0,seg.n,1);
		if(seg.query()<=0) ++res;
	}
	
	cout<<res<<endl;



	return 0;
}