#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto x:arr)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }

const int MAX_N = 100010;

int n;
int cnt = 0;
int a[MAX_N];

bool used[MAX_N];

vec v;

bool odd;

int one;
int two;

void dfs( int x ){
  used[x] = true;
  cnt++;
  if( !used[ a[x] ] ) dfs( a[x] );
}

void dfs2( int x ){
  used[x] = true;
  cout << two+1 << " " << x+1 << endl;
  two = a[two];
  if( !used[ a[x] ] ) dfs2( a[x] );
}

int main(){

  cin >> n;
  REP( i , n ){
    cin >> a[i];
    a[i]--;
  }

  REP( i , n ){
    if( !used[i] ){
      cnt = 0;
      dfs( i );
      if( cnt % 2 == 1 ) odd = true;
      if( cnt == 1 ) one = i;
      if( cnt == 2 ) two = i;
      v.pb( cnt );
    }
  }

  sort( ALL(v) );

  if( v[0] != 1 && ( v[0] != 2 || odd ) ){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  if( v[0] == 1 ){
    REP( i , n ){
      if( i != one )
	cout << one+1 << " " << i+1 << endl;
    }
  } else {
    cout << two+1 << " " << a[two]+1 << endl;
    REP( i , n ) used[i] = false;
    REP( i , n ){
      if( !used[i] && i != two && i != a[two] ) dfs2( i );
    }
  }
  
  return 0;
}