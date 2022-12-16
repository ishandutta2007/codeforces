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
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

string s;
int c;
int mv = INF;
int sc;

int main(){

  cin >> s;
  int n = s.length();

  REP( i , n ){
    if( s[i] == '(' ) c++;
    else c--;
    if( c < 0 ) return puts( "-1" );
    if( s[i] == '#' ) mv = c, sc++;
    chmin( mv , c );
  }

  if( mv < c ) return puts( "-1" );

  REP( i , sc-1  ) printf( "1\n" );
  if( sc > 0 ) printf( "%d\n" , c+1 );
  
  return 0;
}