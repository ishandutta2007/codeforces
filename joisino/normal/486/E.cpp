#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n;
int a[MAX_N];
int dp[MAX_N];
multiset<int> l[MAX_N];
int ans[MAX_N];
int be[MAX_N];
int lis;
int cnt[MAX_N];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , MAX_N ) dp[i] = INF;
  REP( i , n ){
    int p = lower_bound( dp , dp+MAX_N , a[i] ) - dp;
    dp[p] = a[i];
    be[i] = p;
  }

  REP( i , MAX_N ) if( dp[i] != INF ) lis = i;
  l[lis+1].insert( INF );
  
  for( int i = n-1; i >= 0; i-- ){
    int ne = be[i]+1;
    if( l[ne].upper_bound( a[i] ) != l[ne].end() ){
      ans[i] = 2;
      cnt[be[i]]++;
      l[be[i]].insert( a[i] );
    } else ans[i] = 1;
  }

  REP( i , n ) if( ans[i] == 2 && cnt[be[i]] == 1 ) ans[i] = 3;
  
  REP( i , n ) printf( "%d" , ans[i] );
  printf( "\n" );
  
  return 0;
}