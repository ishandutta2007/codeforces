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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

class Permutation : public vi{
public:
  Permutation( int n ){
    resize( n );
    REP( i , n ) at(i) = i;
  }
  Permutation(){}
};

Permutation identity_permutation( int n ){
  Permutation e( n );
  REP( i , n ) e[i] = i;
  return e;
}

Permutation inv( const Permutation &a ){
  Permutation c( a.size() );
  REP( i , a.size() ) c[ a[i] ] = i;
  return c;
}

Permutation operator * ( Permutation a  , Permutation b ){
  assert( a.size() == b.size() );
  Permutation c( a.size() );
  REP( i , a.size() ) c[i] = b[a[i]];
  return c;
}

Permutation operator *=( Permutation &a , Permutation b ){
  return a = a * b;
}

Permutation operator ^ ( Permutation x , ll k ){
  Permutation res = identity_permutation( x.size() );
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}

Permutation operator ^=( Permutation &x , ll k ){
  return x = x ^ k;
}

const int MAX_N = 1000010;

char cs[MAX_N];
string s;

string ans;

int q;
int k, d;

bool used[100][100];
Permutation memo[100][100];

int main(){

  scanf( "%s" , cs ); s = cs;
  scanf( "%d" , &q );

  ans = s;

  int n = s.length();

  Permutation x(n);
  
  REP( query_cnt , q ){
    scanf( "%d %d" , &k , &d );

    Permutation nx( n + n-k );
    REP( i , n ) nx[i] = n-k+x[i];
    REP( i , n-k ) nx[n+i] = i;

    Permutation a( n + n-k );
    
    if( k < 100 && d < 100 && n < 100 && used[k][d] ){
      a = memo[k][d];
    } else {
      REP( i , k ) a[n-k+i] = n-k + ( i % d ) * ( k / d ) + i / d + min( i % d , k % d );
      
      Permutation b( n + n-k );
      FOR( i , 1 , b.size() ) b[i] = i-1;
      b[0] = b.size()-1;

      a *= b;
      a ^= n-k+1;
      a *= inv(b);

      if( k < 100 && d < 100 && n < 100 ){
	used[k][d] = true;
	memo[k][d] = a;
      }
    }

    
    nx *= a;

    REP( i , n ) x[i] = nx[i];

    REP( i , n ) ans[x[i]] = s[i];

    printf( "%s\n" , ans.c_str() );
  }
  
  
  return 0;
}