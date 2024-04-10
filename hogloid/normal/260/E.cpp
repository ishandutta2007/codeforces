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
pi p[100005];
int assign[10];
int xzip[200005],yzip[200005];

int sum[200005],ysum[200005];
struct segtree{
	vector<int> val[800005];
	int n;
	void init(int n_,int n2){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n2) val[p[i].fr+n-1].pb(p[i].sc);
		REP(i,n_) sort(ALL(val[i+n-1]));
		for(int i=n-2;i>=0;--i){
			val[i].resize(val[i*2+1].size()+val[i*2+2].size());
			merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
		}
	}
	int query(int a,int b,int i,int l,int r,int lb,int ub){
		if(a<=l && r<=b) return upper_bound(ALL(val[i]),ub)-lower_bound(ALL(val[i]),lb);
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return query(a,b,i*2+1,l,md,lb,ub)+query(a,b,i*2+2,md,r,lb,ub);
	}
};
segtree seg;
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].fr,&p[i].sc);
	REP(i,9) cin>>assign[i];
	REP(i,n){
		xzip[i]=p[i].fr;
		yzip[i]=p[i].sc;
	}
	sort(xzip,xzip+n);
	sort(yzip,yzip+n);
	int xn=unique(xzip,xzip+n)-xzip,yn=unique(yzip,yzip+n)-yzip;
	REP(i,n){
		p[i].fr=lower_bound(xzip,xzip+xn,p[i].fr)-xzip;
		p[i].sc=lower_bound(yzip,yzip+yn,p[i].sc)-yzip;
		p[i].fr*=2;
		p[i].sc*=2;
	}
	xn*=2;yn*=2;
	sort(p,p+n);
	seg.init(xn,n);
	REP(i,n) sum[p[i].fr]++;
	REP(i,xn) sum[i+1]+=sum[i];
	
	REP(i,n) ++ysum[p[i].sc];
	REP(i,yn) ysum[i+1]+=ysum[i];

	sort(assign,assign+9);
	int m=0;
	do{
		int left=assign[0]+assign[1]+assign[2],mid=assign[3]+assign[4]+assign[5],
			bot=assign[0]+assign[3]+assign[6],midy=assign[1]+assign[4]+assign[7];
		int div1=lower_bound(sum,sum+xn,left)-sum,
			div2=lower_bound(sum,sum+xn,left+mid)-sum,
			div3=lower_bound(ysum,ysum+yn,bot)-ysum,
			div4=lower_bound(ysum,ysum+yn,bot+midy)-ysum;

		if(sum[div1]==left && sum[div2]==left+mid &&
			ysum[div3]==bot && ysum[div4]==bot+midy){
			++div1;++div2;
			++div3;++div4;
			if(seg.query(0,div1,0,0,seg.n,0,div3)==assign[0] &&
				seg.query(0,div1,0,0,seg.n,div4,yn)==assign[2] &&
				seg.query(div2,xn,0,0,seg.n,0,div3)==assign[6] && 
				seg.query(div2,xn,0,0,seg.n,div4,yn)==assign[8]){
				printf("%.10f %.10f\n%.10f %.10f\n",
				(xzip[div1/2]+xzip[div1/2+1])/2.0,
				(xzip[div2/2]+xzip[div2/2+1])/2.0,
				(yzip[div3/2]+yzip[div3/2+1])/2.0,
				(yzip[div4/2]+yzip[div4/2+1])/2.0);
				return 0;
			}

		}
	}while(next_permutation(assign,assign+9));

	puts("-1");
	return 0;
}