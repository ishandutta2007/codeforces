#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};

Mod operator + ( Mod a  , Mod b ){ return Mod( a.n + b.n ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( a.n + MOD - b.n ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( (ll)a.n * b.n ); }
Mod operator *=( Mod &a , Mod b ){ return a = a * b; }
Mod modpow( Mod x , ll k ){
  Mod res = 1;
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}
Mod inv( Mod a ){ return modpow( a , MOD-2 ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }

const ll MAX_N = 200010;
mt19937 mt;
ll MUL;
Mod e[MAX_N];

ll n, m;
char s[MAX_N], t[MAX_N];

ll ns[MAX_N], nt[MAX_N];
vl st;

ll to[26];

bool used[26];

vl ans;

deque<ll> deq[26];

Mod ha, h;

int main(){

  scanf( "%lld %lld" , &n , &m );
  scanf( "%s %s" , s , t );

  mt.seed( clock() );
  MUL = mt() % 100007 + 9393;
  e[0] = 1;
  FOR( i , 1 , MAX_N ) e[i] = e[i-1] * MUL;

  REP( i , m ){
    ll c = t[i] - 'a';
    ha *= MUL;
    ha += deq[c].empty() ? -1 : i - deq[c].back();
    if( deq[c].empty() ) st.pb( i );
    deq[c].push_back( i );
  }

  REP( i , 26 ) deq[i].clear();

  REP( i , n ){
    ll c = s[i] - 'a';
    h *= MUL;
    h += deq[c].empty() ? -1 : i - deq[c].back();
    deq[c].push_back( i );
    if( i >= m ){
      h -= -1 * e[m];
      
      ll p = s[i-m] - 'a';
      deq[p].pop_front();
      if( !deq[p].empty() ){
	ll q = deq[p].front();
	ll v = q-(i-m);
	h -= v * e[m-v];
	h += -1 * e[m-v];
      }
    }
    if( ha.n == h.n ){
      REP( j , 26 ) to[j] = -2;
      YYS( w , st ) to[t[w]-'a'] = s[i-(m-1)+w]-'a';
      
      bool ok = true;
      REP( j , 26 ) used[j] = false;
      REP( j , 26 ) if( !used[j] && to[j] != -2 ){
	if( ( to[ to[j] ] == -2 || to[ to[j] ] == j ) && !used[ to[j] ] ){
	  used[j] = used[ to[j] ] = true;
	} else ok = false;
      }
      if( ok ) ans.pb( i - m + 2 );
    }
  }

  printf( "%lld\n" , SZ(ans) );
  REP( i , SZ(ans) ) printf( "%lld%c" , ans[i] , i == SZ(ans)-1 ? '\n' : ' ' );
  
  return 0;
}