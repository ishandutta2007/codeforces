#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long double ld;
typedef long long int ll;

const int INF = 1e9;
const ll INFLL = 1e18;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

typedef pair<int,int> P;
typedef vector<ll> vec;

const double EPS = 1e-10;

int main(){

  int a, b;
  cin >> a >> b;

  if( a < b ){
    cout << -1 << endl;
    return 0;
  }

  int t = a/b;
  if( t % 2 == 0 ) t--;

  
  double y = (double)(a+b)/(t+1);
  if( t != 0 ) chmin( y , (double)(a-b)/(t-1) );

  cout << setprecision(16) << y << endl;
  
  return 0;
}