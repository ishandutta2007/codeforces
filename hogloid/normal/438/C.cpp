#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<complex>
#include<vector>
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

typedef complex<lint> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
inline lint cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
inline lint dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
inline int sign(lint a){
	if(a==0) return a;
	return a/abs(a);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

typedef vector<P> G;

struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};


inline int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;				  // a--c--b on line (or b==c or a==c)
}

inline bool intersectLP(const P& l1,const P& l2, const P &p) {
  return abs(cross(l2-p, l1-p)) == 0 ;
}
inline bool intersectSS(const P& s1,const P& s2,const P& t1 ,const P& t2) {
  return ccw(s1,s2,t1)*ccw(s1,s2,t2) <= 0 &&
         ccw(t1,t2,s1)*ccw(t1,t2,s2) <= 0;
}

vector<P> convex_hull(vector<P> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

enum { OUT, ON, IN };
int contains(const vector<P>& ps, const P& p) {
  bool in = false;
  int n=ps.size();
  for (int i = 0; i < ps.size(); ++i) {
    P a = ps[i] - p, b = ps[(i+1)%n] - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) <= 0 && 0 < imag(b))
      if (cross(a, b) < 0) in = !in;
    if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
  }
  return in ? IN : OUT;
}

int n;
P ps[205];
vector<P> psv;
lint dp[205][205];
lint mod=1000000007;

bool isok[205][205];

lint rec(int l,int r){
	if(r-l==1) return 1;
	lint& res=dp[l][r];
	if(res!=-1) return res;
	
	res=0;
	for(int i=l+1;i<r;++i) if(isok[l][i] && isok[i][r] && 
			!intersectLP(ps[l],ps[r],ps[i])){
		lint A=rec(l,i),B=rec(i,r);
		res+=A*B%mod;
	}
	res%=mod;
	return res;
}

int main(){
	cin>>n;
	REP(i,n){
		lint a,b;cin>>a>>b;
		a<<=1;b<<=1;
		ps[i].real(a);ps[i].imag(b);
		psv.pb(ps[i]);
	}
	ps[n]=ps[0];
	REP(i,n) REPN(j,n+1,i+1){
		if(i==0 && j==n) continue;
		if(j-i==1 || j-i==n-1) isok[i][j]=1;
		else{
			int cnt=0;
			REP(k,n) if(intersectSS(ps[i],ps[j],ps[k],ps[k+1])) ++cnt;
			P md=(ps[i]+ps[j])/P(2,0);
			if(cnt==4 && contains(psv,md)==IN){
				isok[i][j]=1;
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	lint res=rec(0,n-1);
	
	cout<<res<<endl;
	return 0;
}