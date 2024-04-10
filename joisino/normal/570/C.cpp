#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }

const int MAX_N = 300010;

char s[MAX_N];

int main(){

  int n , m;
  scanf( "%d %d\n" , &n , &m );

  scanf( "%s\n" , s );

  int ans = 0;
  int cnt = 0;
  REP( i , n+1 ){
    if( s[i] == '.' ) cnt++;
    else{
      ans += max( cnt-1 , 0 );
      cnt = 0;
    }
  }

  REP( i , m ){
    int a;
    char c;
    scanf( "%d %c\n" , &a , &c ); a--;
    
    cnt = 0;
    if( a > 0 && s[a-1] == '.' ) cnt++;
    if( a < n-1 && s[a+1] == '.' ) cnt++;

    if( c == '.' && s[a] != '.' ) ans += cnt;
    if( c != '.' && s[a] == '.' ) ans -= cnt;

    s[a] = c;
    
    cout << ans << endl;
  }
  
  return 0;
}