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

typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int MAX_N = 100010;

bool cyclef;

int used[MAX_N];
ll ans = 0;

vector<int> G[MAX_N];

ll cnt[2];

void dfs( int x , int d ){
  used[x] = d;
  cnt[d%2]++;

  REP( i , G[x].size() ){
    int u = G[x][i];
    if( !used[u] ) dfs( u , d+1 );
    else if( (d-used[u])%2 == 0 ) cyclef = true;
  }
}


int main(){

  ll n, m;
  cin >> n >> m;

  REP( i , m ){
    int a, b;
    cin >> a >> b; a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ){
    if( !used[i] ){
      cnt[0] = cnt[1] = 0;
      dfs( i , 1 );
      ans += cnt[0]*(cnt[0]-1)/2 + cnt[1]*(cnt[1]-1)/2;
    }
  }

  if( cyclef ){
    cout << "0 1" << endl;
  } else if( ans > 0 ){
    cout << "1 " << ans << endl;
  } else if( m > 0 ){
    cout << "2 " << m*(n-2) << endl;
  } else {
    cout << "3 " << n*(n-1)*(n-2)/6 << endl;
  }
   
}