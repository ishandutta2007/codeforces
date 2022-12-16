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

const int MAX_N = 100010;

char cs[MAX_N];
string s;

stack<int> st;
int cnt = 0;

int ansv;
int anss = 0;
int anse = 0;

int v[MAX_N];
int p[MAX_N];

int main(){

  REP( i , MAX_N ) p[i] = i;

  scanf( "%s" , cs ); s = cs;
  st.push( -1 );
  REP( i , s.length() ){
    v[i] = cnt;
    if( s[i] == '(' ) st.push( i );
    if( s[i] == '[' ) st.push( i );
    if( s[i] == ')' ){
      if( !st.empty() && s[st.top()] == '(' ){
	if( cnt - v[p[st.top()]] > ansv ){
	  ansv = cnt - v[p[st.top()]];
	  anss = p[st.top()];
	  anse = i+1;
	}
	p[i+1] = p[st.top()];	
	st.pop();
      } else {
	cnt = 0;
	while( !st.empty() ) st.pop();
      }
    } else if( s[i] == ']' ){
      if( !st.empty() && s[st.top()] == '[' ){
	p[i+1] = p[st.top()];
	cnt++;
	if( cnt - v[p[st.top()]] > ansv ){
	  ansv = cnt - v[p[st.top()]];
	  anss = p[st.top()];
	  anse = i+1;
	}
	st.pop();
      } else {
	cnt = 0;
	while( !st.empty() ) st.pop();
      }
    }
  }

  
  printf( "%d\n" , ansv );
  printf( "%s\n" , s.substr( anss , anse-anss ).c_str() );

  return 0;
}