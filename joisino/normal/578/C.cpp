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

typedef pair<int,int> P;
typedef vector<ll> vec;

const int MAX_N = 200010;

int n;
double a[MAX_N];
double na[MAX_N];

double f( double x ){
  REP( i , n )
    na[i] = a[i] - x;

  double minv = 0;
  double maxv = 0;
  double sum = 0;
  REP( i , n ){
    sum += na[i];
    chmax( maxv , sum );
    chmin( minv , sum );
  }
  return maxv - minv;
}

int main(){

  cin >> n;
  REP( i , n )
    cin >> a[i];
  
  double lb = -20000, ub = 20000;
  REP( loop_cnt , 100 ){
    double x1 = (2*lb+ub)/3;
    double x2 = (lb+2*ub)/3;
    if( f(x1) < f(x2) ) ub = x2;
    else lb = x1;
  }

  cout << setprecision(16) << f(lb) << endl;
  
  return 0;
}