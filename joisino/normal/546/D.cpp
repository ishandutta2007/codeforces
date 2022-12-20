#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb emplace_back

using namespace std;

typedef int64_t ll;
typedef long double ld;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-9;

template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

const int MAX_P = 2300;
const int MAX_N = 5000010;

ll val[MAX_N];
ll sum[MAX_N];

bool isnotprime[MAX_P];
vector<int> ps;

int main(){

  FOR( i , 2 , MAX_P ){
    if( isnotprime[i] ) continue;
    ps.pb( i );
    for( int j = i*2; j < MAX_P; j+=i )
      isnotprime[j] = true;
  }


  val[0] = val[1] = 0;
  FOR( i , 2 , MAX_N ){
    val[i] = 1;
    REP( j , ps.size() ){
      if( i % ps[j] == 0 ){
	val[i] = val[i/ps[j]]+1;
	break;
      }
    }
  }

  FOR( i , 1 , MAX_N )
    sum[i] = sum[i-1]+val[i];

  int t;
  scanf( "%d" , &t );

  int a , b;
  REP( i , t ){
    scanf( "%d %d" , &a , &b );
    printf( "%I64d\n" , sum[a] - sum[b] );
  }
    
  
  return 0;
}