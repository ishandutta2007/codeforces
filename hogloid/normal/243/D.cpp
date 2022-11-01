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
static const int INF =1010000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int vx,vy;
int mat[1005][1005],tmp[1005][1005];

int xzip[2000005];
int calc(int y,int x){
	return x*vy-y*vx;
}
struct segtree{
	int val[8000002];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0;
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return INF;
		int md=(l+r)>>1;
		val[i*2+1]=max(val[i*2+1],val[i]);
		val[i*2+2]=max(val[i*2+2],val[i]);
		return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
	void set(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			val[i]=max(v,val[i]);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		val[i*2+1]=max(val[i*2+1],val[i]);
		val[i*2+2]=max(val[i*2+2],val[i]);
		set(a,b,i*2+1,l,md,v);
		set(a,b,i*2+2,md,r,v);
		val[i]=min(val[i*2+1],val[i*2+2]);
	}
};
segtree seg;
int main(){
	scanf("%d%d%d",&n,&vx,&vy);
	swap(vx,vy);
	REP(i,n) REP(j,n) scanf("%d",&mat[i][j]);

	while(!(vx>=0 && vy>0)){
		int nx=-vy,ny=vx;
		REP(i,n) REP(j,n) tmp[i][j]=mat[n-1-j][i];
		vy=ny;
		vx=nx;
		memcpy(mat,tmp,sizeof(mat));
	}
	
	int xn=0;
	REP(i,n) REP(j,n){
		xzip[xn++]=calc(i+1,j);
		xzip[xn++]=calc(i,j+1);
	}
	sort(xzip,xzip+xn);
	xn=unique(xzip,xzip+xn)-xzip;
	seg.init(xn);

	lint res=0;
	REP(i,n) REP(j,n){
		int left=calc(i+1,j),right=calc(i,j+1);
		left=lower_bound(xzip,xzip+xn,left)-xzip;
		right=lower_bound(xzip,xzip+xn,right)-xzip;
		int lowest=seg.query(left,right,0,0,seg.n);
		res+=max(0,mat[i][j]-lowest);
		seg.set(left,right,0,0,seg.n,mat[i][j]);
	}
	cout<<res<<endl;

	return 0;
}