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

vi ps;
vb notp;
int max_p;
void init_p( int mp = 1000010 ){
  max_p = mp;
  notp.resize( max_p , false );
  notp[0] = notp[1] = true;
  FOR( i , 2 , max_p ){
    if( !notp[i] ){
      ps.pb( i );
      for( int j = i*2; j < max_p; j += i )
	notp[j] = true;
    }
  }
}
bool is_prime( int x ){
  if( max_p <= x ) init_p( x+1 );
  return !notp[x];
}


int n;
int a[128];

int dp[128][1<<17];
int add[128][1<<17];

int fact[128];

int main(){

  cin >> n;
  REP( i , n ) cin >> a[i];
  
  init_p();
  
  FOR( i , 1 , 60 )
    REP( j , 20 )
    if( i % ps[j] == 0 ) fact[i] |= 1<<j;

  REP( i , n+1 ) REP( j , 1<<17 ) dp[i][j] = INF;
  dp[0][0] = 0;
  
  REP( i , n ){
    FOR( j , 1 , 60 ){
      int x = (~fact[j]) & ((1<<17)-1);
      for( int k = x; ; k = (k-1)&x ){
	if( dp[i+1][k|fact[j]] > dp[i][k] + abs(a[i]-j) ){
	   dp[i+1][k|fact[j]] = dp[i][k] + abs(a[i]-j);
	  add[i+1][k|fact[j]] = j;
	}
	if( k == 0 ) break;
      }
    }
  }

  int ans = 0;
  REP( i , 1<<17 )
    if( dp[n][i] < dp[n][ans] ) ans = i;

  vi ansv;

  vi x;
  for( int i = n; i > 0; i-- ){
    ansv.pb( add[i][ans] );
    ans -= fact[add[i][ans]];
  }

  reverse(ALL(ansv));

  REP( i , n ){
    if( i != 0 ) cout << " ";
    cout << ansv[i];
  }
  cout << endl;
  
  return 0;
}