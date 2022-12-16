#include "bits/stdc++.h"

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)

#define pb push_back

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }



int n;
int a[100010]; //check the limitation

int l[100010] , r[10001];

int st[100010];

int main(){

  cin >> n;
  
  REP( i , n )
    cin >> l[i] >> r[i];

  for( int i = n-1; i >= 0; i-- ){
    int nl = l[i]/2;
    int nr = (r[i]-1)/2;
    int c;
    
    for( c = 0; i+c < n; ){
      if( nl <= c && c <= nr )
	break;
      c += a[i+c+1]+1;
    }

    if( i+c >= n ){
      cout << "IMPOSSIBLE\n" << endl; //verify
      return 0;
    }

    a[i] = c;
  }


  int p = 0;
  REP( i , n ){
    st[p++] = a[i];
    cout << "(";
    while( p > 0 && st[p-1] <= 0 ){
      cout << ")";
      p--;
      REP( i , p )
	st[i]--;
    }
  }

  cout << endl;
  
  return 0;
}