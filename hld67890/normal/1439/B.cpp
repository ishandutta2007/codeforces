    #pragma GCC optimize(3)
	#include <stdio.h>
    #include <algorithm>
    #include <queue>
    #include <map>
     
    using namespace std;
     
    int n , m , k;
    map < int , int > e[100100];
    int edge[600][100100];
    int pos[120000] , cntpos;
    int d[120000];
    queue < int > q;
    int nei[120000] , tot;
    int alive[120000] , lv;
    void clear () {
    	int i , j;
    	for ( i = 1 ; i <= n ; i++ ) {
    		e[i].clear();
    		d[i] = 0;
    		pos[i] = 0;
    	}
    	for ( i = 1 ; i <= cntpos ; i++ ) {
    		for ( j = 1 ; j <= n ; j++ ) {
    			edge[i][j] = 0;
    		}
    	}
    	cntpos = 0;
    	while ( q.size () ) q.pop();
    }
    int test ( int i ) {
    	int l , flag , ok;
    	//printf ( "%d\n" , i );
    	tot = 0;
    	for ( auto j : e[i] ) {
    		nei[++tot] = j.first;
    	}
    	nei[++tot] = i;
    	flag = 1;
    	sort ( nei + 1 , nei + 1 + tot );
    	for ( int j = 1 ; j <= tot ; j++ ) {
    		if ( pos[nei[j]] ) {
    			for ( l = j + 1 ; l <= tot ; l++ ) {
    				if ( edge[pos[nei[j]]][nei[l]] == 0 ) {
    					flag = 0;
    					break;
    				}
    			}
    		}
    		else {
    			ok = j + 1;
    			for ( auto o : e[nei[j]] ) {
    				if ( ok <= tot && o.first == nei[ok] ) ok++;
    			}
    			if ( ok != tot + 1 ) {
    				flag = 0;
    				break;
    			}
    		}
    		if ( flag == 0 ) break;
    	}
    	if ( flag == 0 ) return 0;
    	printf ( "2\n" );
    	for ( int j = 1 ; j <= tot ; j++ ) {
    		printf ( "%d%c" , nei[j] , j==tot?'\n':' ' );
    	}
    	return 1;
    }
    void work () {
    	int i , l , u , v;
    	scanf ( "%d%d%d" , &n , &m , &k );
    	clear ();
    	for ( i = 1 ; i <= n ; i++ ) {
    		alive[i] = 1;
    	}
    	lv = n;
    	for ( i = 1 ; i <= m ; i++ ) {
    		scanf ( "%d%d" , &u , &v );
    		//u = (i+1) / 2;
    		//v = 50001 + (i%2);
			e[u][v] = e[v][u] = 1;
    		d[u]++;
    		d[v]++;
    	}
    	if ( k == 1 ) {
    		printf ( "2\n" );
    		printf ( "%d\n" , 1 );
    		return ;
    	}
    	if ( k == 2 ) {
    		if ( m == 0 ) {
    			printf ( "-1\n" );
    		}
    		else {
    			printf ( "2\n" );
    			printf ( "%d %d\n" , u , v );
    		}
    		return ;
    	}
    	if ( k > 500 ) {
    		printf ( "-1\n" );
    		return ;
    	}
    	for ( i = 1 ; i <= n ; i++ ) {
    		if ( d[i] > 500 ) {
    			pos[i] = ++cntpos;
    			//printf ( "%d\n" , i );
    			for ( auto j : e[i] ) {
    				edge[pos[i]][j.first] = 1;
    			}
    		}
    	}
    	for ( i = 1 ; i <= n ; i++ ) {
    		if ( d[i] < k - 1 ) {
    			q.push ( i ); 
    		}
    		if ( d[i] == k - 1 ) {
    			if ( test ( i ) == 1 ) {
    				return ;
    			}
    			q.push ( i );
    		}
    	}
    	while ( q.size () ) {
    		l = q.front (); q.pop();
    		alive[l] = 0; lv--;
    		//printf ( "%d\n" , l );
    		for ( auto j : e[l] ) {
    			e[j.first].erase ( l );
    			if ( pos[j.first] ) edge[pos[j.first]][l] = 0;
    			d[j.first]--;
    			if ( d[j.first] == k - 1 ) {
    				if ( test ( j.first ) == 1 ) {
    					return ;
    				}
    				q.push ( j.first ); 
    			}
    		}
    	}
    	if ( lv >= k ) {
    		printf ( "1 %d\n" , lv );
    		for ( i = 1 ; i <= n ; i++ ) {
    			if ( alive[i] == 1 ) {
    				printf ( "%d%c" , i , lv==1?'\n':' ' );
    				lv--;
    			}
    		}
    	}
    	else {
    		printf ( "-1\n" );
    	}
    }
    int main () {
    	int t;
    	scanf ( "%d" , &t );
    	while ( t-- ) work ();
    	return 0;
    }