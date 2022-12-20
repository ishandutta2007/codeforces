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
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const string cl = "RGBYW";

int n;
string s;
int a, b;

int cnt[10][10];

int main(){

  cin >> n;
  REP( i , n ){
    cin >> s;
    REP( i , 5 )
      if( cl[i] == s[0] ) a = i;
    b = s[1]-'1';
    cnt[a][b]++;
  }

  int ans = INF;
  REP( i , 1<<10 ){
    bool ok = true;
    REP( a1 , 5 ) REP( a2 , 5 ) REP( b1 , 5 ) REP( b2 , 5 ){
      if( a1 == a2 && b1 == b2 ) continue;
      if( cnt[a1][b1] == 0 || cnt[a2][b2] == 0 ) continue;
      if( a1 != a2 && ( ( i & ( 1<<a1 ) )  || ( i & ( 1<<a2 ) ) ) ) continue;
      if( b1 != b2 && ( ( i & ( 1<<(b1+5) ) ) || ( i & ( 1<<(b2+5) ) ) ) ) continue;
      ok = false;
    }
    if( ok ) chmin( ans , __builtin_popcount( i ) );
  }

  cout << ans << endl;
  
  return 0;
}