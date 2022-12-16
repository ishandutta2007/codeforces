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
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll hpy, aty, dey;
ll hpm, atm, dem;

ll ca, cb, cc;
ll a, b, c;

ll ans = INFLL;

bool check(){
  ll hy = hpy + a;
  ll ay = aty + b;
  ll dy = dey + c;
  ll day = max( 0LL , atm - dy );
  ll dam = max( 0LL , ay - dem );
  if( dam == 0 ) return false;
  ll t = (hpm-1) / dam + 1;
  if( t * day >= hy ) return false;
  return true;
}

int main(){

  cin >> hpy >> aty >> dey;
  cin >> hpm >> atm >> dem;
  cin >> ca >> cb >> cc;

  
  REP( i , 300 ){
    REP( j , 300 ){
      b = i, c = j;
      ll lb = -1, ub = INF;
      while( ub-lb > 1 ){
	a = (lb+ub)/2;
	if( check() ) ub = a;
	else lb = a;
      }
      chmin( ans , ub * ca + b * cb + c * cc );
    }
  }


  cout << ans << endl;

  return 0;
}