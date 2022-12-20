#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
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
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


const int MAX_N = 256;

int n, k;
ll a[MAX_N];
ll ans = -INFLL;
multiset<ll> in, out;

int main(){

  scanf( "%d %d" , &n , &k );
  REP( i , n ) scanf( "%lld" , &a[i] );

  REP( i , n ){
    in.clear(); out.clear();
    REP( j , n ) if( i != j ) out.insert( a[j] );
    in.insert( a[i] );
    
    ll sum = a[i];
    FOR( j , i+1 , n+1 ){
      ll res = sum;
      if( !out.empty() ){
	auto itei = in.begin();
	auto iteo = out.rbegin();
	REP( l , k ){
	  if( *itei < *iteo ) res += *iteo - *itei;
	  itei++; iteo++;
	  if( itei == in.end() || iteo == out.rend() ) break;
	}
      }
      chmax( ans , res );
      if( j == n ) break;      
      sum += a[j];
      in.insert( a[j] );
      out.erase( out.find( a[j] ) );
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}