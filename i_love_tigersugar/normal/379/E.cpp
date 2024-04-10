//This solution is based on rng_58's solution
#include<bits/stdc++.h>
#define MAX   333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const double eps=1e-9;
typedef pair<double,double> dd;
typedef pair<dd,int> ddi;
class ConvexHull {	
	private:
	double L,R;
	int sz;
	vector<dd> v;
	public:
	ConvexHull() {
		L=0.0;R=0.0;
		sz=0;
	}
	ConvexHull(double L,double R,int n) {
		this->L=L;
		this->R=R;
		v=vector<dd>(3*n+7);
		v[0]=dd(L,0.0);
		v[1]=dd(R,0.0);
		sz=2;
	}
	void addline(double a,double b) {
		int i;
		for (i=sz-1;i>=0;i=i-1)	if (v[i].se>a*v[i].fi+b+eps) break;
		if (i==sz-1) return;
		if (i<0) {
			sz=2;			
			v[0]=dd(L,a*L+b);
			v[1]=dd(R,a*R+b);
			return;
		}
		double a2=(v[i+1].se-v[i].se)/(v[i+1].fi-v[i].fi);
		double b2=v[i].se-a2*v[i].fi;
		double x=-(b2-b)/(a2-a);
		v[i+1]=dd(x,a*x+b);
		v[i+2]=dd(R,a*R+b);
		sz=i+3;
	}
	double area(void) const {
		double ret=0.0;
		REP(i,sz-1) ret+=(v[i+1].fi-v[i].fi)*(v[i+1].se+v[i].se)/2.0;
		return (ret);
	}
};
int a[MAX][MAX];
int n,k;
double res[MAX],uni[MAX];
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	REP(i,n) REP(j,k+1) scanf("%d",&a[i][j]);	
}
void process(void) {
	REP(i,k) {
		vector<ddi> line;
		REP(j,n) line.push_back(ddi(dd(a[j][i+1]-a[j][i],a[j][i]),j));
		sort(line.begin(),line.end());
		REP(j,n) {
			ConvexHull CH=ConvexHull(0.0,1.0,n);
			FORE(it,line) if (it->se<=j) CH.addline(it->fi.fi,it->fi.se);
			uni[j]=CH.area();
			if (j>0) res[j]+=uni[j]-uni[j-1];
			else res[j]+=uni[j];
		}
	}
	REP(i,n) printf("%.07lf\n",res[i]);
}
int main(void) {
	init();
	process();
	return 0;
}