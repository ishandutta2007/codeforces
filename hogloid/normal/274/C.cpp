#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<complex>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define EPS (1e-8)
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
typedef complex<double> P;

int n;
P p[105];
pi q[105];

double cross(P a,P b){
	return a.real()*b.imag()-a.imag()*b.real();
}
double dot(P a,P b){
	return a.real()*b.real()+a.imag()*b.imag();
}

P inv(P a){
	return a*P(0,-1);
}


P intersection_l(P a1, P a2, P b1, P b2) {
  P a = a2 - a1; P b = b2 - b1;
  return a1 + a * cross(b, b1-a1) / cross(b, a);
}

inline bool eq(double a,double b){
	return abs(a-b)<EPS;
}

int main(){
	cin>>n;
	REP(i,n){
		cin>>q[i].fr>>q[i].sc;
	}
	sort(q,q+n);
	REP(i,n){
		p[i].real()=q[i].fr;
		p[i].imag()=q[i].sc;
	}

	double res=-1;
	REP(i,n) REP(j,i) REP(k,j){
		if(dot(p[j]-p[i],p[k]-p[i])<EPS ||
			dot(p[i]-p[j],p[k]-p[j])<EPS ||
			dot(p[i]-p[k],p[j]-p[k])<EPS) continue;
		
		P m1=(p[i]+p[j])/2.0,m2=(p[i]+p[k])/2.0,m3=(p[j]+p[k])/2.0;

		P m12=m1+inv(p[j]-p[i]),m22=m2+inv(p[k]-p[i]),m32=m3+inv(p[k]-p[j]);

		P c=intersection_l(m1,m12,m2,m22);
		double dst=abs(c-p[i]);
		
		int fail=0;
		REP(l,n) if(l!=i && l!=j && l!=k){
			if(dst>abs(c-p[l])+1e-10){
				fail=1;break;
			}
		}
		if(!fail) res=max(res,dst);
	}
	REP(i,n) REP(j,n) REP(k,n) if(i!=j && j!=k && i!=k){
		if(abs(dot(p[j]-p[i],p[k]-p[j]))<EPS){
			pi s=mp(q[i].fr+(q[k].fr-q[j].fr),q[i].sc+(q[k].sc-q[j].sc));
			if(binary_search(q,q+n,s)){
				double dst=abs(p[k]-p[i])/2.0;
				int s2=lower_bound(q,q+n,s)-q;
				P c=(p[i]+p[k])/2.0;
				
				int fail=0;
				REP(l,n) if(l!=i && l!=j && l!=k && l!=s2){
					if(dst>(abs(c-p[l])+1e-10)){
						fail=1;break;
					}
				}
				if(!fail){
					res=max(res,dst);
				}
			}
		}
	}

			
	if(res<0) puts("-1");
	else printf("%.10f\n",res);

	return 0;
}