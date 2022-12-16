#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto x:arr)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }
void pvec( vec &v ){
  REP( i , v.size() ){
    if( i != 0 ) cout << " ";
    cout << v[i];
  }
  cout << endl;
}


const int MAX_P = 1000010;
vec ps;
vector<bool> notp;
void init_p(){
  notp.resize( MAX_P );
  FOR( i , 2 , MAX_P ){
    if( !notp[i] ){
      ps.pb( i );
      for( int j = i*2; j < MAX_P; j += i )
	notp[j] = true;
    }
  }
}

int main(){

  init_p();

  vec ans;
  
  ll n = in();
  REPR( p , ps ){
    ll res = p;
    while( res <= n ){
      ans.pb( res );
      res *= p;
    }
  }

  cout << ans.size() << endl;
  pvec( ans );
  
  return 0;
}