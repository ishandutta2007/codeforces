#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<complex>
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

typedef complex<double> P;
P ps[105];
int m;
const double PI=acos(-1.0);
const double PREC=10000000;

double cross(const P& a,const P& b){
	return a.real()*b.imag()-a.imag()*b.real();
}

int is_intersected_ls(P a1, P a2, P b1, P b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < -1e-15 ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < -1e-15 );
}
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}

int all,one,two;

unsigned int xor128(void) { 
  static unsigned int x = 123456789;
  static unsigned int y = 362436069;
  static unsigned int z = 521288629;
  static unsigned int w = 88675123; 
  unsigned int t;
 
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}
bool solve(){
	++all;
	m=0;
	ps[m++]=P(0.0,0.0);
	double ang=0;
	P cur=P(0.0,0.0);
	REP(i,n-2){
		double len=(xor128()%((int)PREC))/PREC*30+1;
		P delta=polar(len,ang);
		ang+=2*PI/n;

		P nxt=delta+cur;
		ps[m++]=nxt;
		cur=nxt;
	}

	P a1=ps[m-1],a2,b1=ps[0],b2;
	a2=a1+polar(1000.0,ang);
	ang+=2*PI/n;
	b2=b1-polar(1000.0,ang);
	if(!is_intersected_ls(a1,a2,b1,b2)) return false;
	++one;
	P plast=intersection_ls(a1,a2,b1,b2);

	if(abs(plast-ps[0])<=1.0 || abs(plast-ps[m-1])<=1.0) return false;

	ps[m++]=plast;

	ps[m]=ps[0];
	REP(i,m) REP(j,i){
		double dst1=abs(ps[i+1]-ps[i]),dst2=abs(ps[j+1]-ps[j]);
		if(dst1/dst2<=1+1e-3 && dst2/dst1<=1+1e-3) return false;
	}
	return true;
}


int main(){
	cin>>n;

	if(n<=4){
		puts("No solution");
		return 0;
	}

	while(solve()==false) ;
	
	double L=1e10,B=1e10;
	REP(i,n){
		L=min(L,ps[i].real());
		B=min(B,ps[i].imag());
	}


	REP(i,n) printf("%.10f %.10f\n",ps[i].real(),ps[i].imag());

	return 0;
}