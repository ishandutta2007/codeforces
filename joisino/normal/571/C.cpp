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

const int MAX_N = 200010;

int sv[MAX_N*2];
set<int> ss[MAX_N];

int ans[MAX_N];
bool used[MAX_N];

int main(){

  int *v = sv + MAX_N; 

  int n, m;
  cin >> n >> m;

  priority_queue<P,vector<P>,greater<P> > que;
  FOR( i , 1 , n+1 ){
    int k;
    scanf( "%d" , &k );
    REP( j , k ){
      int a;
      scanf( "%d" , &a );
      ss[i].insert( a );
      v[a] = i;
    }
    que.push( P( ss[i].size() , i ) );
  }


  while( !que.empty() ){
    P p = que.top();
    que.pop();

    int x = p.se;

    if( used[x] ) continue;
    used[x] = true;

    if( ss[x].size() == 0 ){
      printf( "NO\n" );
      return 0;
    }

    int s = *ss[x].begin();
    if( s > 0 ) ans[abs(s)] = 1;

    int ai = v[-s];
    if( ai != 0 ){
      ss[ai].erase( -s );
      que.push( P( ss[ai].size() , ai ) );
    }
  }

  printf( "YES\n" );
  FOR( i , 1 , m+1 )
    printf( "%d" , ans[i] );
  printf( "\n" );
  
  return 0;
}