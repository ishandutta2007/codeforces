#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long long int ll;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

typedef pair<int,int> P;
typedef vector<ll> vec;

const int MAX_N = 100010;
const int MAX_L = 100010;
const int MAX_D = 210;

int asum;
int sum[MAX_L];

int n;
vector<P> ps;

int l[MAX_N];
int d[MAX_N];

int ds[MAX_N];

int cn[MAX_N];

int main(){

  cin >> n;
  REP( i , n )
    cin >> l[i];

  REP( i , n )
    cin >> d[i];

  
  REP( i , n )
    ps.pb( P( l[i] , d[i] ) );
  sort( ALL(ps) );

  REP( i , n )
    sum[ l[i] ] += d[i];
  REP( i , MAX_L-1 )
    sum[i+1] += sum[i];
  REP( i , n )
    asum += d[i];

  REP( i , n )
    cn[ l[i] ]++;

  /*
  REP( i , n ){
    cout << ps[i].fi << " " << ps[i].se << endl;
  }
  return 0;
  */
  
  int ans = INF;
  REP( i , n ){
    int res = asum - sum[ ps[i].fi ];
    int rc = i - cn[ ps[i].fi ] + 1;
    REP( j , MAX_D ){
      if( rc <= ds[j] ){
	res += j*rc;
	break;
      } else {
	res += j*ds[j];
	rc -= ds[j];
      }
    }
    chmin( ans , res );
    //cout << i << " " << res << endl;
    ds[ ps[i].se ]++;
  }

  cout << ans << endl;
  
  return 0;
}