#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
struct seg{
	double left,right,sum;
};
seg list[30];
int cnt;
struct segtree{
	double val[600005],left[600005],right[600005],sum[600005];
	int n;
	void init(int n_,double* exp){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0;
		REP(i,n_) val[i+n-1]=exp[i];
		REPN(i,n,n_) val[i+n-1]=0;
		REP(i,n){
			if(val[i+n-1]>0) left[i+n-1]=right[i+n-1]=val[i+n-1];
			else left[i+n-1]=right[i+n-1]=0;
			sum[i+n-1]=val[i+n-1];
		}
		for(int i=n-2;i>=0;--i){
			left[i]=max(left[i*2+1],sum[i*2+1]+left[i*2+2]);
			right[i]=max(right[i*2+2],right[i*2+1]+sum[i*2+2]);
			sum[i]=sum[i*2+1]+sum[i*2+2];
			val[i]=max(right[i*2+1]+left[i*2+2],max(val[i*2+1],val[i*2+2]));
		}
	}
	double query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			list[cnt++]=(seg){left[i],right[i],sum[i]};
			return val[i];
		}
		if(b<=l || r<=a) return 0;
		int md=(l+r)/2;
		double lef=query(a,b,i*2+1,l,md),rig=query(a,b,i*2+2,md,r);
		return max(lef,rig);
	}
};
segtree seg_t;
double each[200000];
int dst[200000];
double found[200005];
double sum[30];
int n,m,c;
int main(){
	scanf("%d%d%d",&n,&m,&c);
	REP(i,n) scanf("%d",&dst[i]);
	REP(i,n-1) scanf("%lf",&found[i]),found[i]/=100.0;
	REP(i,n-1){
		each[i]=(dst[i+1]-dst[i])/2.0-found[i]*c;
	}
	seg_t.init(n-1,each);
	double ans=0;
	REP(hoge,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		cnt=0;
		double res=seg_t.query(a,b,0,0,seg_t.n);
		sum[0]=0;
		REP(i,cnt) sum[i+1]=sum[i]+list[i].sum;
		REP(i,cnt) REPN(j,cnt,i+1){
			res=max(res,sum[j]-sum[i+1]+list[i].right+list[j].left);
		}
		ans+=res;
	}
	printf("%.8f\n",ans);


	return 0;
}