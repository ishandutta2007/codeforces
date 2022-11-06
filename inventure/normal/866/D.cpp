#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 50;

int n , p[maxn] , cnt[maxn];
priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > > pq;

int main( int argc , char * argv[] ){
	scanf( "%d" , & n );
	for(int i = 1 ; i <= n ; ++ i) scanf( "%d" , p + i );
	long long ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if( !pq.empty() && p[i] > pq.top().first ){
			ans += p[i] - pq.top().first;
			int sce = pq.top().second;
			cnt[i] = 1;
			pq.pop();
			if( cnt[sce] == 1 ){
				cnt[sce] = 0;
				pq.push( make_pair( p[sce] , sce ) );
			}
		}
		pq.push( make_pair( p[i] , i ) );
	}
	printf( "%lld\n" , ans );
	return 0;
}