#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<complex>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int spr(int x){
	return x*x;
}
typedef complex<double> P;
int n,d;
pair<P,int> circ[20000];
const double PI=acos(-1.0);

pair<double,int> event[20005*21*2*3];
int main(){
	cin>>n>>d;
	REP(i,n){
		double a,b;cin>>a>>b>>circ[i].sc;
		circ[i].fr.real(a);
		circ[i].fr.imag(b);
	}
	
	int m=0;
	REP(i,n){
		double dist=abs(circ[i].fr);
		double theta=atan2((double)circ[i].fr.imag(),(double)circ[i].fr.real());

		REP(j,5000) if(j*d<=dist+circ[i].sc && dist-circ[i].sc<=j*d){
			
			double a=dist,b=d*j,c=circ[i].sc;;
			double cosval=(a*a+b*b-c*c)/(2*a*b);

			double phi=acos(cosval);
			event[m++]=mp(theta+phi,-1);
			event[m++]=mp(theta-phi-1e-10,1);
		}
	}
	int m2=m;
	REP(i,m2){
		event[m]=event[i];
		event[m].fr+=2*PI;
		++m;

		event[m]=event[i];
		event[m].fr+=4*PI;
		++m;
	}
	sort(event,event+m);
	int sum=0,res=0;
	REP(i,m){
		sum+=event[i].sc;
		chmax(res,sum);
	}
	cout<<res<<endl;


				




	return 0;
}