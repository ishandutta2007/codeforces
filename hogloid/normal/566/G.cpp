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
int sign(lint a){
  if(a==0) return a;
  return a/abs(a);
}

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  return 0;
}



vector<P> convex_hull(vector<P> ps) {// return counter-clockwise
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) < 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) < 0) --k;
  ch.resize(k-1);
  return ch;
}

P ps[200005];
int n,m;
set<P> S,mx;
int main(){
  cin>>n>>m;
  scanf("%*d%*d");
  int top=0,rig=0;
  REP(i,n+m){
    int a,b;scanf("%d%d",&a,&b);
    P t(a,b);
    S.insert(t);
    if(i<n) mx.insert(t);
    else{
      chmax(rig,a);
      chmax(top,b);
    }
  }
  vector<P> cv;
  for(auto e:S) cv.pb(e);
  cv.pb(P(rig,0));
  cv.pb(P(0,top));
  cv.pb(P(0,0));
  vector<P> hull=convex_hull(cv);
  for(auto e:hull) if(mx.count(e)){
    puts("Max");
    return 0;
  }
  puts("Min");
  return 0;
}