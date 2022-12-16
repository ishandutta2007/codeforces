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

char ca[MAX_N], cb[MAX_N];
ll n, m;
string a, b;

ll na, nb;
ll g;

int cnt[MAX_N][30];
ll ans;

int main(){

  scanf( "%lld %lld\n" , &n , &m );
  scanf( "%s\n" , ca ); a = ca; 
  scanf( "%s\n" , cb ); b = cb;
  if( a.length() < b.length() ){ swap( a , b ); swap( n , m ); }
  na = a.length();
  nb = b.length();
  g = __gcd( na , nb );
  REP( i , na ) cnt[i%g][a[i]-'a']++;
  REP( i , nb ) ans += cnt[i%g][b[i]-'a'];
  ans = na*nb/g - ans;
  ans *= n*g/nb;
  printf( "%lld\n" , ans );
  
  return 0;
}