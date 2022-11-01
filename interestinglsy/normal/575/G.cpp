#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(1e9))
#define LINF ((int)(1e18))
#define out cout <<
#define ln  << endl
#define pb push_back
#define mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define mp make_pair
#define sint short int
#define ull unsigned ll
#define pq priority_queue
#define pii pair<int,int>
#define uint unsigned int
#define B out "BreakPoint\n";
#define read(_num) scanf("%d",&_num)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_num1,_num2) scanf("%d %d",&_num1,&_num2)
#define msn(_data,_num) memset(_data,_num,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_num1,_num2,_num3) scanf("%d %d %d",&_num1,&_num2,&_num3)
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%I64d ",_x);}
#define MAXN 100005 //Maxn means "MAXM"

int n , m;
vc< pii > e[MAXN];
set<int> s , ns;
pii par[MAXN];	// F: dis_to_ed		S: Posid
//parSecond

int dis_to_ed[MAXN] , dis_to_st[MAXN];
int par_from_ed[MAXN] , par_from_st[MAXN];
void bfs( int st_pos , int dist[] , int par[] , bool zero_only ){
	bool able_to_go[13];
	ms( able_to_go );
	able_to_go[0] = 1;
	if( !zero_only ) fill( able_to_go+1 , able_to_go + 10 , 1 );
	fill( dist , dist+n+2 , INF );
	dist[st_pos] = 0;

	queue<int> q;	//	Dotid , Dist to st
	q.push( st_pos );
	while( !q.empty() ){
		int now = q.front();
		q.pop();
		for( uint i = 0 ; i < e[now].size() ; i++ ){
			pii u = e[now][i];
			if( able_to_go[u.S]  &&  dist[now] + 1 < dist[u.F] ){
				dist[u.F] = dist[now]+1;
				par[u.F] = now;		//
				q.push( u.F );
			}
		}
	}
}

int main(){
//	fin( "beer.txt" );

	read2( n , m );
	for( int i = 1 ; i <= m ; i++ ){
		int a , b , w;
		read3( a , b , w );
		e[a].pb( mp( b , w ) );
		e[b].pb( mp( a , w ) );
	}

	bfs( n-1 , dis_to_ed , par_from_ed , 1 );
	bfs( 0 , dis_to_st , par_from_st , 0 );

	/*
	cout << "[STdis]\n";
	for( int i = 0 ; i < n ; i++ )
		cout << dis_to_st[i] << " ";
	cout << endl;
	cout << "[EDdis]\n";
	for( int i = 0 ; i < n ; i++ )
		cout << dis_to_ed[i] << " ";
	cout << endl;
	*/

	int min_dis_to_st = INF;
	for( int i = 0 ; i < n ; i++ )
		if( dis_to_ed[i] != INF )
			mymin( min_dis_to_st , dis_to_st[i] );

	fill( par , par + n + 2 , mp( INF , 0 ) );
	for( int i = 0 ; i < n ; i++ )
		if( dis_to_ed[i] < INF )
			if( dis_to_st[i] == min_dis_to_st ){
				s.insert( i );
				par[i] = mp( dis_to_ed[i] , i );
			}

	for( int i = 0 ; i < min_dis_to_st ; i++ ){
		ns.clear();
		int min_path = INF;
		for( set<int>::itor it = s.begin() ; it != s.end() ; it++ ){
			int np = *it;
			for( uint j = 0 ; j < e[np].size() ; j++ ){
				int u = e[np][j].F;
				int udis = e[np][j].S;
				if( dis_to_st[u] + 1 != dis_to_st[np] ) continue;
				if( udis < min_path ){
					min_path = udis;
					ns.clear();
				}//else{
					if( udis == min_path ){
						if( ns.find( u ) != ns.end() ){
							mymin( par[u] , mp( par[np].F , np ) );
						}else{
							ns.insert( u );
							par[u] = mp( par[np].F , np );
						}
					}
				//}
			}
		}
		printf("%d",min_path);
		s = ns;
	}

	if( !min_dis_to_st ) printf("0");
	printf("\n");

	int tot = min_dis_to_st + par[0].F;
	printf("%d\n", tot + 1 );
	int pos = 0;
	for (int i = 0; i < min_dis_to_st; i++) {
		printf("%d ", pos);
		pos = par[pos].S;
	}
	for (int i = 0; i < tot - min_dis_to_st; i++) {
		printf("%d ", pos);
		pos = par_from_ed[pos];
	}
	printf("%d\n", pos);
	return 0;
}