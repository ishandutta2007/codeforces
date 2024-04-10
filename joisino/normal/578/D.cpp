#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second



ll cnt[256];

int n , m;
string s;

int main(){

  cin >> n >> m;
  cin >> s;

  REP( i , n )
    cnt[ s[i] ]++;

  ll par = 0;
  REP( i , m )
    par += (ll)n - cnt['a'+i];

  
  ll ans = 0;
  char prev = '#';
  REP( i , n ){
    if( prev != s[i] ) ans += par;
    prev = s[i];
  }

  if( n >= 2 ){
    ll st = 0;
    prev = s[0];
    char next = s[1];
    FOR( i , 2 , n ){
      if( s[i] != prev ){
	if( prev != next ) ans -= ll(i-st)*ll(i-st-1)/2;
	st = i-1;
      }
      prev = next;
      next = s[i];
    }
    if( prev != next ) ans -= ll(n-st)*ll(n-st-1)/2;
  }
  
  cout << ans << endl;
  
  return 0;
}