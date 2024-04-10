#include "bits/stdc++.h"
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
 
const int INF = 1e9;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

const int MAX_M = 100010;

vector<int> v[2];
ll s[2], p[2];

ll m;
ll h[2], a[2];
ll x[2], y[2];

int main(){
  
  cin >> m;
  REP( t , 2 ){
    cin >> h[t] >> a[t];
    cin >> x[t] >> y[t];
  }

  REP( t , 2 ){
    s[t] = -1;
    p[t] = 1e18;
    v[t] = vector<int>( m , -1 );
    REP( i , 2*m+1 ){
      if( h[t] == a[t] && v[t][h[t]] != -1 ){
	p[t] = i - v[t][h[t]];
	break;
      }
      v[t][h[t]] = i;
      if( h[t] == a[t] ) s[t] = i;
      h[t] = ( x[t] * h[t] + y[t] ) % m;
    }
  }

  if( s[0] == -1 || s[1] == -1 ){
    cout << -1 << endl;
    return 0;
  }

  //cout << s[0] << " " << s[1] << " " << p[0] << " " << p[1] << endl;

  REP( i , 2*m+1 ){
    //cout << s[1] << " " << s[0] << " " << s[0] << endl;
    if( s[1] >= s[0] && (s[1]-s[0])%p[0] == 0 ){
      cout << s[1] << endl;
      return 0;
    }
    s[1] += p[1];
    if( s[1] >= 1e18 ){
      cout << -1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  
  return 0;
}