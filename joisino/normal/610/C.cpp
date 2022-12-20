#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define pb emplace_back
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1024;

int n;

string ans[MAX_N];

void rec( int sz ){
  if( sz == 0 ){
    ans[0] = "+";
    return;
  }

  rec( sz-1 );

  REP( i , PW(sz-1) ) ans[i+PW(sz-1)] = ans[i];
  REP( i , PW(sz) ) ans[i] += ans[i];
  FOR( i , PW(sz-1) , PW(sz) ) FOR( j , PW(sz-1) , PW(sz) ){
    if( ans[i][j] == '+' ) ans[i][j] = '*';
    else ans[i][j] = '+';
  }
}

int main(){

  scanf( "%d" , &n );

  rec( n );
  
  REP( i , PW(n) ) printf( "%s\n" , ans[i].c_str() );
  
  return 0;
}