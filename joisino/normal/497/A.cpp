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
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 128;

int n, m;
string s[MAX_N];
bool used[MAX_N];

int main(){

  cin >> n >> m;
  REP( i , n )
    cin >> s[i];

  int ans = 0;
  REP( i , m ){
    bool ok = true;
    REP( j , n-1 )
      if( !used[j] )
	if( s[j][i] > s[j+1][i] ) ok = false;
    
    if( !ok ) ans++;
    else REP( j , n-1 )
	   if( s[j][i] < s[j+1][i] ) used[j] = true;
  }

  cout << ans << endl;
  
  return 0;
}