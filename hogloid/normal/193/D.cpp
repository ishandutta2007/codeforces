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
struct segtree{
	struct node{
		int add,mini,cnt1,cnt2;
	};
	node val[1200005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			val[i+n-1].cnt1=1;
			val[i+n-1].cnt2=0;
		}
		for(int i=n-2;i>=0;--i) update(i);
	}
	void push(int i){
		if(val[i].add){
			val[i*2+1].add+=val[i].add;
			val[i*2+1].mini+=val[i].add;
			val[i*2+2].add+=val[i].add;
			val[i*2+2].mini+=val[i].add;
		}
	}
	void update(int i){
		val[i].mini=min(val[i*2+1].mini,val[i*2+2].mini);
		val[i].add=0;
		int dif[3];
		dif[1]=val[i*2+1].mini-val[i].mini;
		dif[2]=val[i*2+2].mini-val[i].mini;
		val[i].cnt1=val[i].cnt2=0;

		for(int t=1;t<=2;++t){
			if(dif[t]==0){
				val[i].cnt1+=val[i*2+t].cnt1;
				val[i].cnt2+=val[i*2+t].cnt2;
			}else if(dif[t]==1) val[i].cnt2+=val[i*2+t].cnt1;
		}
	}
	void add(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			val[i].add+=v;
			val[i].mini+=v;
			return;
		}
		if(b<=l || r<=a) return;
		push(i);
		int md=(l+r)>>1;
		add(a,b,i*2+1,l,md,v);
		add(a,b,i*2+2,md,r,v);
		update(i);
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			return val[i].cnt2*(val[i].mini==1)+val[i].cnt1*(val[i].mini<=2);
		}
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r);
	}
};
segtree seg;
int n;
int p[300005],rev[300005];
int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%d",&p[i]);
		--p[i];
		rev[p[i]]=i;
	}
	seg.init(n);
	p[n]=-1;
	
	lint ans=0;
	for(int i=n-1;i>=0;--i){
		int pos=rev[i];
		int a=-1,b=-1;
		if(pos>0) b=p[pos-1];
		a=p[pos+1];

		if(a<i) a=-1;
		if(b<i) b=-1;

		if(a>b) swap(a,b);

		if(a>=0 && b>=0){
			seg.add(i,a,0,0,seg.n,1);
			seg.add(b,n,0,0,seg.n,-1);
		}else if(b>=0){
			seg.add(i,b,0,0,seg.n,1);
		}else{
			seg.add(i,n,0,0,seg.n,1);
		}
		ans+=seg.query(i,n,0,0,seg.n);
	}
	ans-=n;
	cout<<ans<<endl;
	return 0;
}