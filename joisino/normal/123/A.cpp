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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

class Primes : public vi{
public:
  Primes( int max_n ){
    vb isp( max_n , true );
    FOR( i , 2 , max_n ){
      if( isp[i] ){
	pb( i );
	for( int j = i*2; j < max_n; j += i ) isp[j] = false;
      }
    }
  }
};

const int MAX_N = 1024;

Primes ps( MAX_N );

int cnt[MAX_N];
int maxind;

char s[MAX_N];

bool irr[MAX_N];
int irr_cnt;

vector<char> v;
string ans;

int main(){

  scanf( "%s" , s );
  int n = strlen( s );

  REP( i , n ) cnt[ s[i]-'a' ]++;
  REP( i , MAX_N ) if( cnt[maxind] < cnt[i] ) maxind = i;
  REP( i , n ) if( s[i] - 'a' != maxind ) v.pb( s[i] );

  irr[0] = true;
  irr_cnt = 1;
  YYS( w , ps ) if( w <= n && w * 2 > n ){
    irr[w-1] = true;
    irr_cnt++;
  }

  if( n - irr_cnt > cnt[maxind] ) return puts( "NO" );

  printf( "YES\n" );
  REP( i , n ){
    if( irr[i] ){
      if( v.empty() ){
	ans += 'a' + maxind;
      } else {
	ans += v.back();
	v.pop_back();
      }
    } else {
      ans += 'a' + maxind;
    }
  }

  printf( "%s\n" , ans.c_str() );
  
  return 0;
}