#include "stdio.h"
#include "set"
#include "algorithm"

using namespace std;

typedef long long int ll;

int w , h , n;
multiset<int> hs,vs;
multiset<int> lh,lv;

int main(){

  scanf( "%d %d %d\n" , &w , &h , &n );

  hs.insert( 0 );
  hs.insert( h );
  vs.insert( 0 );
  vs.insert( w );
  lh.insert( h );
  lv.insert( w );
  
  for( int i = 0; i < n; i++ ){
    char c;
    int p;
    scanf( "%c %d\n" , &c , &p );
    if( c == 'H' ){
      hs.insert( p );
      set<int>::iterator ite = hs.find( p );
      set<int>::iterator itep = ite; itep--;
      set<int>::iterator iten = ite; iten++;
      set<int>::iterator itee = lh.find( *iten - *itep );      
      lh.erase( itee );
      lh.insert( *ite - *itep );
      lh.insert( *iten - *ite );
    } else if( c == 'V' ){
      vs.insert( p );
      set<int>::iterator ite = vs.find( p );
      set<int>::iterator itep = ite; itep--;
      set<int>::iterator iten = ite; iten++;
      set<int>::iterator itee = lv.find( *iten - *itep );
      lv.erase( itee );
      lv.insert( *ite - *itep );
      lv.insert( *iten - *ite );

      /*
      ite = lv.begin();
      for( ; ite != lv.end() ; ite++ )
	printf( "%d " , *ite );
      printf( "\n" );
      */
      
    }

    printf( "%I64d\n" , ll(*lh.rbegin()) * ll(*lv.rbegin()) );
  }
  
  return 0;
}