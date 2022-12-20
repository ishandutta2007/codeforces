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
 
ll in(){ ll a; cin >> a; return a; }
 
#define fi first
#define se second

typedef pair<ll,ll> P;
typedef vector<ll> vec;

string rec( string s ){
  if( s.length() % 2 == 0 ){
    string s1 = rec( s.substr( 0 , s.length()/2 ) );
    string s2 = rec( s.substr( s.length()/2 ) );
    if( s1 < s2 ) return s1 + s2;
    return s2 + s1;
  }
  return s;
}

string s[2];
  
int main(){
  
  REP( i , 2 ){
    cin >> s[i];
    s[i] = rec( s[i] );
  }

  if( s[0] == s[1] ) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}