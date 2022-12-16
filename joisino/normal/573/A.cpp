#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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

int a[MAX_N];

int main(){

  int n = in();

  REP( i , n ){
    cin >> a[i];
    while( a[i] % 2 == 0 ) a[i] /= 2;
    while( a[i] % 3 == 0 ) a[i] /= 3;
  }

  REP( i , n ){
    if( a[i] != a[0] ){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  
  return 0;
}