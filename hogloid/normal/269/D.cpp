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
static const int INF =1000000005; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
struct segtree{
	int val[800005],all[800005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=-1,all[i]=-1;
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return -1;
		int md=(l+r)>>1;
		if(all[i]!=-1){
			all[i*2+1]=all[i*2+2]=val[i*2+1]=val[i*2+2]=all[i];
			all[i]=-1;
		}
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
	void set(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			val[i]=v;
			all[i]=v;
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		if(all[i]!=-1){
			all[i*2+1]=all[i*2+2]=val[i*2+1]=val[i*2+2]=all[i];
			all[i]=-1;
		}
		set(a,b,i*2+1,l,md,v);
		set(a,b,i*2+2,md,r,v);
		val[i]=max(val[i*2+1],val[i*2+2]);
	}
};
segtree seg;
pair<int,pi> wall[100005];
int zip[200005];
int n,t;
int dp[100005];

void doit(int l,int r,int who,int excL=1,int excR=1){
	int id=seg.query(l,r,0,0,seg.n);
	if(id==-1){
		seg.set(l,r,0,0,seg.n,who);
		dp[who]=zip[r]-zip[l];
		return;
	}
	int l2=wall[id].sc.fr,r2=wall[id].sc.sc;
	if(!(l2<l && excL==0) && !(r<r2 && excR==0)){
		dp[who]=max(dp[who],min(dp[id],min(zip[r],zip[r2])-max(zip[l],zip[l2])));
	}

	if(l<l2) doit(l,l2,who,excL,0);
	if(r2<r) doit(r2,r,who,0,excR);
}

int main(){
	scanf("%d%d",&n,&t);
	REP(i,n){
		int a,b,h;scanf("%d%d%d",&h,&a,&b);
		zip[i*2]=a;
		zip[i*2+1]=b;
		wall[i]=mp(h,mp(a,b));
	}

	zip[n*2]=-INF;
	zip[n*2+1]=INF;
	sort(zip,zip+n*2+2);
	int zn=unique(zip,zip+n*2+2)-zip;
	wall[n++]=mp(0,mp(-INF,INF));
	wall[n++]=mp(t,mp(-INF,INF));
	REP(i,n){
		wall[i].sc.fr=lower_bound(zip,zip+zn,wall[i].sc.fr)-zip;
		wall[i].sc.sc=lower_bound(zip,zip+zn,wall[i].sc.sc)-zip;
	}
	sort(wall,wall+n);
	
	seg.init(zn);
	REP(i,n){
		int h=wall[i].fr,l=wall[i].sc.fr,r=wall[i].sc.sc;
		
		doit(l,r,i);
		seg.set(l,r,0,0,seg.n,i);
	}
	printf("%d\n",dp[n-1]);


	return 0;
}