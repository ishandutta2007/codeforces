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
const ld EPS = 1e-11;

template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

typedef pair<ll,ll> P;
#define fi first
#define se second

typedef vector<int> vec;

map<vec,bool> mp;

int sf,ss;
deque<int> pf,ps;

int main(){

  int n;
  cin >> n;

  int m;
  cin >> m;
  REP( i , m ){
    int a;
    cin >> a;
    pf.push_back( a );
    sf += 1<<a;
  }

  cin >> m;
  REP( i , m ){
    int a;
    cin >> a;
    ps.push_back( a );
    ss += 1<<a;
  }

  int cnt;
  for( cnt = 0; 1; cnt++ ){
    vec v;
    for( auto ite = pf.begin(); ite != pf.end(); ite++ )
      v.pb( *ite );
    v.pb( INF );
    for( auto ite = ps.begin(); ite != ps.end(); ite++ )
      v.pb( *ite );
    
    if( mp[v] ){
      cout << -1 << endl;
      break;
    }
    mp[v] = true;

    if( pf.empty() ){
      cout << cnt << " " << 2 << endl;
      break;
    }
    if( ps.empty() ){
      cout << cnt << " " << 1 << endl;
      break;
    }

    int cf = pf.front(); pf.pop_front();
    int cs = ps.front(); ps.pop_front();

    if( cf < cs ){
      ps.push_back( cf );
      ps.push_back( cs );
    } else {
      pf.push_back( cs );
      pf.push_back( cf );
    }
  }

  return 0;
}