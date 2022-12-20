#include "bits/stdc++.h"
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
 
const int INF = 1e9;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

int a[128];

int main(){

  string s;
  cin >> s;

  int n = s.length();

  REP( i , n )
    a[i] = s[i]-'0';
  
  REP( i , n ){
    FOR( j , i+1 , n ){
      FOR( k , j+1 , n ){
	if( ( a[i]*100 + a[j]*10 + a[k] ) % 8 == 0 ){
	  if( a[i] == 0 ){
	    REP( l , i ){
	      if( a[l] != 0 ){
		cout << "YES" << endl;
		cout << a[l] << a[i] << a[j] << a[k] << endl;
		return 0;
	      }
	    }
	  } else {
	    cout << "YES" << endl;	    
	    cout << a[i] << a[j] << a[k] << endl;
	    return 0;
	  }
	}
      }
    }
  }

  REP( i , n ){
    FOR( j , i+1 , n ){
      if( ( a[i]*10 + a[j] ) % 8 == 0 ){
	if( a[i] != 0 ){
	  cout << "YES" << endl;
	  cout << a[i] << a[j] << endl;
	  return 0;
	}
      }
    }
  }

  REP( i , n ){
    if( a[i] == 8 || a[i] == 0 ){
      cout << "YES" << endl;
      cout << a[i] << endl;
      return 0;
    }
  }

  cout << "NO" << endl;  
  
  return 0;
}