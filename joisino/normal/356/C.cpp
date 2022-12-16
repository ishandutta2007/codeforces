#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1000010;

int n;
int a;
int b[5];
int cnt;
int ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ){ scanf( "%d" , &a ); b[a]++; cnt+=a; }
  if( cnt == 1 || cnt == 2 || cnt == 5 ) return puts( "-1" );
  int fs = min( b[1] , b[2] );
  b[1] -= fs; b[2] -= fs; b[3] += fs;
  if( b[2] >= 1 ){
    ans = (b[2]/3)*2;
    if( b[2] % 3 == 2 ) ans += 2;
    if( b[2] % 3 == 1 ){
      if( b[4] >= 1 ) ans++;
      else ans += 2;
    }
  } else if( b[1] >= 1 ){
    ans = (b[1]/3)*2;
    b[3] += b[1]/3;
    if( b[1] % 3 == 1 && b[3] == 0 ) ans += 2;
    else ans += b[1]%3;
  }
  ans += fs;
  printf( "%d\n" , ans );

  return 0;
}