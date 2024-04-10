#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long long int ll;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second


const int MAX_N = 5010;

int k;
string s;

bool pf[MAX_N][MAX_N];
deque<int> pv[MAX_N];

int main(){

  cin >> s;
  cin >> k;

  int n = s.length();

  REP( l , n ){
    REP( x , n ){
      if( x+l < n && s[x] == s[x+l] && ( l <= 4 || pf[x+2][x+l-2] ) ){
	pf[x][x+l] = true;
	pv[x].pb( x+l );
      }
    }
  }

  string ans = "";

  REP( ap , n ){
    int e = 0, a = 0, b = 0;
    REP( x , n ){
      if( !pv[x].empty() && pv[x][0] == x+ap-1 ){
	e++;
	pv[x].pop_front();
      }
      if( x+ap < n ){
	if( s[x+ap] == 'a' ) a += pv[x].size();
	else b += pv[x].size();
      }
    }

    if( k <= e ) break;

    if( k <= a+e ){
      ans += 'a';
      k -= e;
      REP( x , n )
	if( s[x+ap] == 'b' ) pv[x].clear();
    } else {
      ans += 'b';
      k -= e+a;
      REP( x , n )
	if( s[x+ap] == 'a' ) pv[x].clear();
    }
  }

  cout << ans << endl;
  
  return 0;
}