#include "stdio.h"
#include "algorithm"
#include "vector"
#include "queue"

using namespace std;

typedef long long int ll;

const ll MOD = 1000000009;

struct cube{
  int x , y , id;
  cube(){}
  cube( int x , int y , int id ) : x(x) , y(y) , id(id) {}
  bool operator < ( const cube& a ) const {
    if( x != a.x ) return x < a.x;
    if( y != a.y ) return y < a.y;
    return id < a.id;
  }
};

vector<cube> cs;
int ue[100010][3];
int sh[100010][3];

int x[100010];
int y[100010];

ll ex[100010];

bool used[100010] = {};


bool checks( int x ){
  int cnt = 0;
  for( int i = 0; i < 3; i++ ){
    if( sh[x][i] != -1 ){
      cnt++;
    }
  }
  if( cnt == 1 ) return true;
  return false;
}

bool check( int x ){
  for( int i = 0; i < 3; i++ ){
    if( ue[x][i] != -1 && checks( ue[x][i] ) ){
      return false;
    }
  }
  return true;
}

int main(){

  int n;
  scanf( "%d" , &n );


  ex[0] = 1;
  for( int i = 1; i <= n; i++ ){
    ex[i] = ex[i-1] * n % MOD;
  }

  for( int i = 0; i < n; i++ ){
    scanf( "%d %d" , &x[i] , &y[i] );
    cs.push_back( cube( x[i] , y[i] , i ) );
  }

  sort( cs.begin() , cs.end() );

  for( int i = 0; i < n; i++ ){
    ue[i][0] = ue[i][1] = ue[i][2] = -1;
    sh[i][0] = sh[i][1] = sh[i][2] = -1;
  }

  for( int i = 0; i < n; i++ ){
    for( int j = -1; j <= 1; j++ ){
      int ux = x[i] + j;
      int uy = y[i] + 1;
      vector<cube>::iterator ite = lower_bound( cs.begin() , cs.end() , cube( ux , uy , -1 ) );
      if( (*ite).x == ux && (*ite).y == uy ){
	ue[i][j+1] = (*ite).id;
      }
    }

    for( int j = -1; j <= 1; j++ ){
      int ux = x[i] + j;
      int uy = y[i] - 1;
      vector<cube>::iterator ite = lower_bound( cs.begin() , cs.end() , cube( ux , uy , -1 ) );
      if( (*ite).x == ux && (*ite).y == uy ){
	sh[i][j+1] = (*ite).id;
      }
    }    
  }


  priority_queue<int,vector<int>,greater<int> > ques;
  priority_queue<int> quel;
  for( int i = 0; i < n; i++ ){
    if( check(i) ){
      ques.push( i );
      quel.push( i );
    }
  }

  ll ans = 0;

  for( int i = 0; i < n; i++ )
    used[i] = false;

  int c = 1;
  while( 1 ){
    int ni;
    if( c % 2 == 1 ){
      if( quel.empty() ) break;
      ni = quel.top();
      quel.pop();
    } else {
      if( ques.empty() ) break;
      ni = ques.top();
      ques.pop();
    }
    if( used[ni] ) continue;
    if( !check(ni) ) continue;
    used[ni] = true;

    /*
    if( ni == 0 ){
      for( int i = 0; i < 3; i++ )
	printf( "%d " , sh[1][i] );
      printf( "\n" );
      for( int i = 0; i < 3; i++ )
	printf( "%d " , ue[0][i] );
      if( check(0) ) printf( "aaa\n" );
      return 0;
    }
    */

    ans += ex[n-c]*ni;
    ans %= MOD;
    c++;

    //printf( "%d %I64d\n" , ni , ans );    

    
    for( int i = 0; i < 3; i++ ){
      if( sh[ni][i] != -1 ){
	int s = sh[ni][i];

	for( int j = 0; j < 3; j++ )
	  if( ue[s][j] == ni ) ue[s][j] = -1;
	if( check(s) ){
	  ques.push( s );
	  quel.push( s );
	}
      }
      if( ue[ni][i] != -1 ){
	int u = ue[ni][i];
	
	for( int j = 0; j < 3; j++ )
	  if( sh[u][j] == ni ) sh[u][j] = -1;
      }
    }
  }

  printf( "%I64d\n" , ans );

  return 0;
}