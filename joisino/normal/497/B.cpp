#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 200010;

int n;
int a[MAX_N];

int ca, cb;
int sa[MAX_N], sb[MAX_N];
int pa[MAX_N], pb[MAX_N];

int main(){

  
  cin >> n;
  REP( i , MAX_N )
    pa[i] = pb[i] = INF;
  
  REP( i , n ){
    cin >> a[i];
    
    sa[i+1] = sa[i];
    sb[i+1] = sb[i];
    
    if( a[i] == 1 ){
      ca++;
      pa[ca] = i+1;
      sa[i+1]++;
    } else {
      cb++;
      pb[cb] = i+1;
      sb[i+1]++;
    }
  }

  /*
  REP( i , n+1 )
    cout << pa[i] << " ";
  cout << endl;
  REP( i , n+1 )
    cout << sa[i] << " ";
  cout << endl;
  */

  vector<pi> ans;
  FOR( s , 1 , n+1 ){
    int c = 0;
    int wa = 0, wb = 0;
    FOR( t , 1 , INF ){
      int nc = min( pa[sa[c]+s] , pb[sb[c]+s] );
      
      if( pa[sa[c]+s] < pb[sb[c]+s] ) wa++;
      else wb++;
      
      if( nc == INF ) break;
      if( nc == n ){
	if( wa == wb ) break;
	if( wa < wb && pa[sa[c]+s] < pb[sb[c]+s] ) break;
	if( wb < wa && pa[sa[c]+s] > pb[sb[c]+s] ) break;
	else ans.pb( pi( max( wa , wb ) , s ) );
      }
      c = nc;
      //cout << s << " " << t << " " << c << endl;
    }
  }

  sort( ALL( ans ) );

  printf( "%d\n" , ans.size() );
  REPR( x , ans )
    printf( "%d %d\n" , x.fi , x.se );
  
  return 0;
}