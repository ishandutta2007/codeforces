#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;
typedef complex<lint> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
lint cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
lint dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

const double PI=acos(-1.0);
int n;
P ps[3005];

pair<int,double> ang[6005];


int dist[5000000];


int solve(){
	int res=0;
	REP(i,n){
		int m=0;
		REP(j,n){
			ang[m++]=mp(norm(ps[j]-ps[i]),
					atan2((double)ps[j].imag()-ps[i].imag(),(double)ps[j].real()-ps[i].real()));
		}
		sort(ang,ang+m,greater<pair<int,double> >());

		set<double> ever;
		REP(j,m){
			double a=ang[j].sc;
			auto it=ever.lower_bound(a+PI/3);
			if(it!=ever.end() && *it<=a+PI/3*5){
				chmax(res,ang[j].fr);
				break;
			}
			ever.insert(a);
			ever.insert(a+2*PI);
		}
	}
	return res;
}

int main(){
	cin>>n;
	REP(i,n){
		int x,y;cin>>x>>y;
		ps[i].real(x);
		ps[i].imag(y);
	}
	
	int res=solve();
	printf("%.10f\n",sqrt((double)res)/2);




	return 0;
}