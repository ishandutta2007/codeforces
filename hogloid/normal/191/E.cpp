#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define ALL(t) (t).begin(),(t).end()
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef vector<int> vi;
typedef pair<int,int> pi;
int n;
lint k;
int eager[100005];
lint sum[100005];
struct segtree{
	vector<lint> val[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_) val[i+n-1].pb(sum[i]);
		for(int i=n-2;i>=0;--i){
			val[i].resize(val[i*2+1].size()+val[i*2+2].size());
			merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
		}
	}
	int query(int a,int b,int i,int l,int r,lint v){
		if(a<=l && r<=b){
			return val[i].end()-lower_bound(ALL(val[i]),v);
		}
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return query(a,b,i*2+1,l,md,v)+query(a,b,i*2+2,md,r,v);
	}
};
segtree seg;
int main(){
	cin>>n>>k;
	REP(i,n) scanf("%d",&eager[i]);
	sum[0]=0;
	REP(i,n) sum[i+1]=sum[i]+eager[i];
	seg.init(n+1);
	lint lb=-1e14-5,ub=-lb;
	while(ub-lb>1){
		lint md=(ub+lb)>>1;
		lint upper=0;
		REP(i,n) upper+=seg.query(i+1,n+1,0,0,seg.n,sum[i]+md);
		if(upper>=k) lb=md;
		else ub=md;
	}
	cout<<lb<<endl;
	return 0;
}