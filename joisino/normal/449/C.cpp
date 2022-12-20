#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

vi ps;
vb isp;
int max_p;
void init_p( int mp = 1000010 ){
  max_p = mp;
  ps.clear();
  isp.resize( max_p+1 , true );
  isp[0] = isp[1] = false;
  FOR( i , 2 , max_p+1 ){
    if( isp[i] ){
      ps.pb( i );
      for( int j = i*2; j <= max_p; j += i )
	isp[j] = false;
    }
  }
}

const int MAX_N = 100010;

ll n;
vpi ans;

vi ss[MAX_N];
bool used[MAX_N];

int main(){

  scanf( "%lld" , &n );
  init_p( n );

  FOR( i , 2 , n+1 ){
    REP( j , ps.size() ){
      if( i % ps[j] == 0 ){
	ss[j].pb( i );
	break;
      }
    }
  }

  for( int i = ps.size()-1; i >= 0; i-- ){
    int j = ss[i].size()-1;
    ll prev = -1;
    while( j >= 0 ){
      if( !used[ss[i][j]] ){
	if( prev == -1 ){
	  prev = ss[i][j];
	} else {
	  ans.pb( pi( ss[i][j] , prev ) );
	  used[ ss[i][j] ] = used[ prev ] = true;
	  prev = -1;
	}
      }
      j--;
    }
    if( prev != -1 && prev*2 <= n ){
      if( !used[prev] && !used[prev*2] ){
	ans.pb( pi( prev , prev*2 ) );
	used[prev] = used[prev*2] = true;
      }
    }
  }

  printf( "%d\n" , ans.size() );
  REPR( a , ans )
    printf( "%d %d\n" , a.fi , a.se );

  return 0;
}