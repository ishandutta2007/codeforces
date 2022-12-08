#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n , m , deg;
vector < pair<int,int> > out[220000];
vector < pair<int,int> > hav[220000] , h2[220000];
int eg[22][22][22] , now[22];
int taboo[22][22];
int ans , a[120];
bool cmp ( pair<int,int> x1 , pair<int,int> x2 ) {
	return x1.second < x2.second;
}
bool cmp2 ( pair<int,int> x1 , pair<int,int> x2 ) {
	if ( x1.first == x2.first ) return x1.second < x2.second;
	return x1.first < x2.first;
}
void dfs ( int i ) {
	if ( i == deg + 1 ) {
		ans++;
		//for ( int k = 1 ; k <= deg ; k++ ) {
		//	printf ( "%d " , a[k] );
		//}
		//printf ( "\n" );
		return ;
	}
	for ( int j = 1 ; j <= i ; j++ ) {
		if ( taboo[i][j] == 0 ) {
			for ( int k = i + 1 ; k <= deg ; k++ ) {
				for ( int l = 1 ; l <= k ; l++ ) {
					if ( eg[i][j][k] & (1<<l) ) taboo[k][l]++;
				}
			}
			dfs ( i + 1 );
			for ( int k = i + 1 ; k <= deg ; k++ ) {
				for ( int l = 1 ; l <= k ; l++ ) {
					if ( eg[i][j][k] & (1<<l) ) taboo[k][l]--;
				}
			}
		}
	}
}
void work () {
	int i , j , k , u , v , w;
	scanf ( "%d%d%d" , &n , &m , &deg );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d%d" , &u , &v , &w );
		out[u].push_back ( make_pair(v,w) );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		sort ( out[i].begin () , out[i].end() , cmp );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 0 ; j < out[i].size() ; j++ ) {
			hav[out[i][j].first].push_back(make_pair(out[i].size(),j+1));
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( hav[i].size () == 0 ) {
			printf ( "0\n" );
			return ;
		}
		sort ( hav[i].begin () , hav[i].end() , cmp2 );
		//printf ( "%d\n" , i );
		for ( j = 0 ; j < hav[i].size () ; j++ ) {
			if ( j == 0 || hav[i][j] != hav[i][j-1] ) {
				h2[i].push_back ( hav[i][j] );
				//printf ( "%d %d\n" , hav[i][j].first , hav[i][j].second );
			}
			else {
				taboo[hav[i][j].first][hav[i][j].second]++;
			}
		}
		for ( j = 1 ; j <= deg ; j++ ) now[j] = 0;
		for ( j = 0 ; j < h2[i].size () ; j++ ) {
			now[h2[i][j].first] |= (1<<h2[i][j].second);
		}
		for ( j = 0 ; j < h2[i].size () ; j++ ) {
			for ( k = 1 ; k <= deg ; k++ )
				eg[h2[i][j].first][h2[i][j].second][k] |= now[k];
		}
	}
	dfs ( 1 );
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}