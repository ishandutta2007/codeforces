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
typedef complex<double> P;
const double PI=acos(-1.0);
P rotate(P a,double ang){
	return P(a.real()*cos(ang)-a.imag()*sin(ang),
		a.real()*sin(ang)+a.imag()*cos(ang));
}
double cross(P a,P b){
	return a.real()*b.imag()-a.imag()*b.real();
}

P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}

int main(){
	int w,h,a;cin>>w>>h>>a;
	if(h>w) swap(w,h);
	if(a>90) a=180-a;
	if(a==0){
		printf("%.10f\n",(double)h*w);
		return 0;
	}

	double alpha=a/180.0*PI;

	P rt=P(w,h),rb=P(w,-h),lb=P(-w,-h);
	P lb2=rotate(lb,alpha),rb2=rotate(rb,alpha);
		
	double res=w*(double)h*4;
	

	if(rb2.imag()+1e-8<h){
		P p=intersection_ls(lb2,rb2,lb,rb);
		double d=abs(rb-p);
		res-=d*d*tan(alpha)/2.0*2;
		double d2=abs(p-rb2)-d/cos(alpha);
		res-=d2*d2/tan(alpha)/2.0*2;
	}else{
		P p=intersection_ls(lb2,rb2,lb,rb);
		P p2=p+P(cos(alpha),sin(alpha))/sin(alpha)*2.0*(double)h;

		double d1=abs(rb-p),d2=abs(rt-p2);
		res-=(d1+d2)*2*h/2.0*2;
	}

	res/=4;

	printf("%.10f\n",res);

	return 0;
}