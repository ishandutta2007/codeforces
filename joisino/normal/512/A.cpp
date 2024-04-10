#include "stdio.h"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

vector<int> G[30];
vector<int> ans;

bool used[30] = {};
bool usedt[30] = {};

bool imp = false;

void dfs( int i ){
  if( used[i] ) return;

  usedt[i] = true;
  for( int j = 0; j < G[i].size(); j++ ){
    if( imp ) return;
    if( !usedt[G[i][j]] ){
      dfs( G[i][j] );
    } else {
      imp = true;
      return;
    }
  }

  if( !used[i] ) ans.push_back( i );
  used[i] = true;
  usedt[i] = false;
}

int main(){

  int n;
  scanf( "%d" , &n );

  vector<string> ns;

  for( int i = 0; i < n; i++ ){
    char str[128];
    scanf( "%s" , str );
    ns.push_back( str );
  }

  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < i; j++ ){
      bool same = true;
      for( int k = 0; k < min(ns[i].length(),ns[j].length()); k++ ){
	if( ns[i][k] != ns[j][k] ){
	  same = false;
	  G[ ns[i][k]-'a' ].push_back( ns[j][k]-'a' );
	  break;
	}
      }

      if( same && ns[i].length() < ns[j].length() ){
	printf( "Impossible\n" );
	return 0;
      }
    }
  }

  for( int i = 0; i < 26; i++ ){
    if( !used[i] ) dfs( i );
  }

  if( !imp ){
    for( int i = 0; i < 26; i++ )
      printf( "%c" , 'a'+ans[i] );
    printf( "\n" );
  } else {
    printf( "Impossible\n" );
  }

  return 0;
}