#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
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
struct BIT{
	int val[200005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=-INF;
	}
	void set(int k,int a){
		++k;
		while(k<=n){
			val[k]=max(val[k],a);
			k+=k&-k;
		}
	}
	int query(int k){//...k)
		int res=-INF;
		while(k>0){
			res=max(res,val[k]);
			k-=k&-k;
		}
		return res;
	}
};

BIT bit;
int n;
double a,b,c,d;
pi p[100005],q2[100005];
pair<double,double> q[100005];
double xzip[100005],yzip[100005];
void fix(double&a,double&b){
	double abs=sqrt(a*a+b*b);
	a/=abs;
	b/=abs;
}
int dp[100005];
int main(){
	int xn=0,yn=0;
	scanf("%d",&n);
	scanf("%lf/%lf %lf/%lf",&a,&b,&c,&d);
	swap(a,b);
	swap(c,d);
	fix(a,b);
	fix(c,d);

	REP(i,n) scanf("%d%d",&p[i].fr,&p[i].sc);
	
	int xn2=0,yn2=0,m=0;
	REP(i,n){
		int e=p[i].fr,f=p[i].sc;
		pair<double,double> tmp=mp((c*f-d*e)/(b*c-a*d),
			((b*e-a*f)/(b*c-a*d)));
		if(tmp.fr>1e-10 && tmp.sc>1e-10){
			q[m++]=tmp;
			xzip[xn2++]=tmp.fr;
			yzip[yn2++]=tmp.sc;
		}
	}
	xzip[xn2++]=0;
	yzip[yn2++]=0;
	sort(xzip,xzip+xn2);
	sort(yzip,yzip+yn2);
	xn=yn=0;
	REP(i,xn2){
		int j=i;
		while(j<xn2 && xzip[j]-xzip[i]<1e-10) ++j;
		xzip[xn++]=xzip[i];
	}

	REP(i,yn2){
		int j=i;
		while(j<yn2 && yzip[j]-yzip[i]<1e-10) ++j;
		yzip[yn++]=yzip[i];
	}

	REP(i,m){
		q2[i].fr=lower_bound(xzip,xzip+xn,q[i].fr-1.5e-10)-xzip;
		q2[i].sc=lower_bound(yzip,yzip+yn,q[i].sc-1.5e-10)-yzip;
	}
	bit.init(yn);
	bit.set(0,0);
	REP(i,m) dp[i]=-INF;
	sort(q2,q2+m);
	REP(i,m){
		int j=i;
		while(j<m && q2[j].fr==q2[i].fr) ++j;
		REPN(k,j,i) dp[k]=bit.query(q2[k].sc)+1;
		REPN(k,j,i) bit.set(q2[k].sc,dp[k]);
		i=j-1;
	}
	int res=0;
	REP(i,m) res=max(res,dp[i]);

	cout<<res<<endl;

	return 0;
}