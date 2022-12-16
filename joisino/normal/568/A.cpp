#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }


const int MAX_N = 10000010;

bool p[MAX_N];

ll a, b;

ll k;
ll x[10];

bool isr(){
  REP( i , k )
    if( x[i] != x[k-1-i] ) return false;
  return true;
}

int main(){

  p[0] = p[1] = true;
  FOR( i , 2 , MAX_N ){
    if( !p[i] ){
      for( int j = i*2; j < MAX_N; j += i )
	p[j] = true;
    }
  }

  cin >> a >> b;
  
  ll ans = 0;

  ll pi = 0, rub = 0;
  
  FOR( i , 1 , MAX_N ){
    x[0]++;
    REP( j , 10 ){
      if( x[j] == 10 ){
	x[j+1]++;
	x[j] = 0;
      }
      if( x[j] != 0 )
	chmax( k , ll(j+1) );
    }

    if( !p[i] ) pi++;
    if( isr() ) rub++;

    if( b * pi <= a * rub ) ans = i;
  }

  if( ans == MAX_N-1 ) cout << "Palindromic tree is better than splay tree" << endl;
  else cout << ans << endl;
  
  return 0;
}