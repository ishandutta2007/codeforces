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
	lint val[400005],all[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0,all[i]=-1;
	}
	void push(int i){
		if(all[i]!=-1){
			all[i*2+1]=val[i*2+1]=all[i];
			all[i*2+2]=val[i*2+2]=all[i];
			all[i]=-1;
		}
	}
	void renew(int a,int b,int i,int l,int r,lint v){
		if(a<=l && r<=b){
			val[i]=v;
			all[i]=v;
			return;
		}
		if(b<=l || r<=a) return;
		push(i);
		int md=(l+r)>>1;
		renew(a,b,i*2+1,l,md,v);
		renew(a,b,i*2+2,md,r,v);
		val[i]=max(val[i*2+1],val[i*2+2]);
	}
	lint query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return -1;
		int md=(l+r)>>1;
		push(i);
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};

segtree seg;

int n;
int ar[100005];

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ar[i]);
	

	seg.init(n);
	REP(i,n) seg.renew(i,i+1,0,0,seg.n,ar[i]);

	int q;scanf("%d",&q);
	REP(hoge,q){
		int w,h;scanf("%d%d",&w,&h);
		lint tall=seg.query(0,w,0,0,seg.n);
		cout<<tall<<endl;


		seg.renew(0,w,0,0,seg.n,tall+h);
	}






	return 0;
}