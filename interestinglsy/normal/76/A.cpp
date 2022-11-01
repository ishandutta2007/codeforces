#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define INF INT_MAX
#define in cin >>
#define LINF LONG_LONG_MAX
#define out cout <<
#define ln  << endl
#define pb push_back
#define mp make_pair
#define ll long long
#define sint short int
#define ull unsigned ll
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
#define MAXN 251
#define MAXM 50100
ull mymax( ull a , ull b ){
	return a>b?a:b;
}
ull mymin( ull a , ull b ){
	return a<b?a:b;
}

int n , m;
ull costg , costs;

struct Edge{
	int from , to;
	ull g,s;
	Edge(){
		from = to = g = s = 0;
	}
	Edge( int fro , int too , ull ggg , ull sss ){
		from = fro;
		to = too;
		g = ggg;
		s = sss;
	}
	void readin(){
		scanf("%d %d %I64d %I64d",&from,&to,&g,&s);
		g *= costg;
		s *= costs;
	}
};
bool operator<( Edge e1 , Edge e2 ){
	return e1.s < e2.s;
}
bool cmp( Edge e1 , Edge e2 ){
	if( e1.g != e2.g ) return e1.g < e2.g;
	return e1 < e2;
}
bool cmp2( Edge e1 , Edge e2 ){
	return e1 < e2;
}
Edge e[MAXM];

int dsu[MAXN];
void init(){
	for( int i = 0 ; i <= n+4 ; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}
bool unite( int a , int b ){
	int aa = getfa(a);
	int bb = getfa(b);
	if( aa == bb ) return 0;
	dsu[aa] = bb;
	return 1;
}

ull LIMIT;
ull ans = LINF;
Edge sta[MAXM];
bool del[MAXM];

int main(){
//	fin("gift.txt");

	scanf("%d %d",&n,&m);
	scanf("%I64d %I64d",&costg,&costs);
	for( int i = 0 ; i < m ; i++ ){
		Edge now = Edge(0,0,0,0); now.readin();
		e[i] = now;
	}

	sort( e , e+m , cmp );

	int nowedge = 0;
	for( int i = 0 ; i < m ; i++ ){
		LIMIT = e[i].g;
		sta[nowedge] = e[i];
		nowedge++;
		
		inplace_merge( sta , sta+nowedge-1 , sta+nowedge , cmp2 );

		init(); ms( del );
		int cnt = 0 , pos = 0;
		ll maxs = 0;
		for( pos = 0 ; pos < nowedge ; pos++ ){
			if( unite( sta[pos].from , sta[pos].to ) ){
				cnt++;
				maxs = mymax( maxs , sta[pos].s );
			}else{
				del[pos] = 1;
			}
			if( cnt >= n-1 ) break;
		}

		if( cnt == n-1 )
			ans = min( ans , LIMIT + maxs );

		int k = 0;
		for( int j = 0 ; j < nowedge ; j++ ){
			if( !del[j] ){
				sta[k] = sta[j];
				k++;
			}
		}

		nowedge = k;
	}

	if( ans == LINF ) printf("-1\n");
	else printf("%I64d\n",ans);
}