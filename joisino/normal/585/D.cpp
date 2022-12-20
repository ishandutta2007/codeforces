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
 
ll in(){ ll a; cin >> a; return a; }
 
#define fi first
#define se second
 
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<P> vecP;


int n;
int a[32][3];

typedef pair<P,ll> PI;
typedef pair<PI,ll> PII;
typedef pair<P,vec> PV;
typedef pair<ll,vec> IV;

vector<PII> s1;
vector<PII> s2;

set<PI> ss1, ss2;

void rec( int k , vec x , ll y ){
  if( k >= min( 13 , n ) ){
    s1.pb( PII( PI( P(  x[1]-x[0] , x[2]-x[0] ) , -x[0] ) , y ) );
    return;
  }

  REP( i , 3 ){
    vec nx = x;
    REP( j , 3 )
      nx[j] += a[k][j];
    nx[i] -= a[k][i];
    ll ny = y * 4 + i + 1;
    rec( k+1 , nx , ny );
  }
}

void rec2( int k , vec x , ll y ){
  if( k <= 12 ){
    s2.pb( PII( PI( P( x[1]-x[0] , x[2]-x[0] ) , -x[0] ) , y ) );
    return;
  }

  REP( i , 3 ){
    vec nx = x;
    REP( j , 3 )
      nx[j] += a[k][j];
    nx[i] -= a[k][i];
    ll ny = y * 4 + i+1;
    rec2( k-1 , nx , ny );
  }
}

string s[3];

int main(){

  s[0] = "MW";
  s[1] = "LW";
  s[2] = "LM";

  cin >> n;

  REP( i , n )
    REP( j , 3 )
    cin >> a[i][j];
  
  vec x( 3 , 0 );
  ll y = 0;

  rec( 0 , x , y );
  rec2( n-1 , x , y );

  sort( ALL( s1 ) );

  vector<IV> anss;
  
  REP( i , s2.size() ){
    P mo = P( - s2[i].fi.fi.fi , - s2[i].fi.fi.se );
    vector<PII>::iterator ite = lower_bound( ALL( s1 ) , PII( PI( mo , -INFLL ) , -INFLL ) );
    if( (*ite).fi.fi == mo ){
      vec a;
      ll la = (*ite).se;
      while( la > 0 ){
	a.pb( la % 4 - 1 );
	la /= 4;
      }
      ll lb = s2[i].se;
      vec b;
      while( lb > 0 ){
	b.pb( lb % 4 - 1 );
	lb /= 4;
      }
      reverse( ALL( a ) );
      a.insert( a.end() , ALL(b) );
      anss.pb( IV( -s2[i].fi.se - (*ite).fi.se , a ) );
    }
  }

  sort( ALL( anss ) );
  reverse( ALL( anss ) );

  if( anss.size() == 0 ){
    cout << "Impossible" << endl;
  }else{
    vec a = anss[0].se;
    REP( i , a.size() )
      cout << s[a[i]] << endl;
  }
  
  return 0;
}