#include "bits/stdc++.h"

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)

#define pb push_back

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }


typedef pair<char,char> P;
const P INI = P( -1 , -1 );

string S;
int n;

vector<P> G[256][256];

int cnt[256][256];
P s[2] = { INI , INI };

P st;

string ans;

void dfs( char x , char y ){
  while( !G[x][y].empty() ){
    char nx = G[x][y].back().first;
    char ny = G[x][y].back().second;
    G[x][y].pop_back();
    dfs( nx , ny );
  }
  ans += y;
}

int main(){

  cin >> n;
  
  REP( i , n ){
    cin >> S;
    G[S[0]][S[1]].push_back( P( S[1] , S[2] ) );
    cnt[S[0]][S[1]]++;
    cnt[S[1]][S[2]]--;
  }

  REP( i , 256 ){
    REP( j , 256 ){
      if( cnt[i][j] >= 1 ){
	if( s[0] != INI || cnt[i][j] >= 2 ){
	  cout << "NO" << endl;
	  return 0;
	}
	s[0] = P( char(i) , char(j) );
      }

      if( G[i][j].size() >= 1 ){
	s[1] = P( char(i) , char(j) );
      }
    }
  }

  if( s[0] != INI ) st = s[0];
  else st = s[1];

  dfs( st.first , st.second );
  ans += st.first;
  reverse( ans.begin() , ans.end() );

  if( ans.size() == n+2 ){
    cout << "YES" << endl;
    cout << ans << endl;
  } else {
    cout << "NO" << endl;
  }

  
  return 0;
}