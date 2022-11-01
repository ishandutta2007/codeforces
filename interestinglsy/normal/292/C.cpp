#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF (1e9)
#define in cin >>
#define LINF (1e18)
#define out cout <<
#define ln  << endl
#define pb push_back
#define mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
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
_tp<_tyn T>void print(T _x){for(auto _it=_x.begin();_it!=_x.end();_it++)cout<<*_it<<" ";cout ln;}
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%lld ",_x);}
void bprint(ll _x){cout<<bitset<10>(_x)<<endl;}

int n;
bool canuse[12];
ll need;
bool good[277];
ll mask[277];
int weis[277][7];
int len[277];
vc<string> ans;

int main(){
//	fin( "ip.txt" );
	ms( canuse );
	need = 0;
	
	read( n );
	for( int i = 1 ; i <= n ; i++ ){
		int x;
		read( x );
		canuse[x] = 1;
		need |= ( 1 << x );
	}
	
	for( int i = 0 ; i < 256 ; i++ ){
		int wei1 = i / 100 , wei2 = ( i % 100 ) / 10 , wei3 = ( i % 100 ) % 10;
		mask[i] = 0; len[i] = 1;
		if( wei1 ){
			mask[i] |= ( 1 << wei1 );
			len[i] = 3;
			weis[i][1] = wei1;
		}
		if( wei2  ||  wei1 ){
			mask[i] |= ( 1 << wei2 );
			weis[i][2] = wei2;
			if( !wei1 ) len[i] = 2;
		}
		mask[i] |= ( 1 << wei3 );
		weis[i][3] = wei3;
		if( ( mask[i] & need ) != mask[i] ) good[i] = 0;
		else good[i] = 1;
	}
	
	/*
	srand(time(0));int x = rand()%256;
	cout << x << " ";
	bprint(mask[x]);
	return 0;
	*/
	
	char cs[17];
	string s,a;
	for( int wei1 = 0 ; wei1 < 256 ; wei1++ )
	if( good[wei1] )
		for( int wei2 = 0 ; wei2 < 256 ; wei2++ )
		if( good[wei2] )
			for( int wei3 = 0 ; wei3 < 256 ; wei3++ )
			if( good[wei3] ){
				if( (mask[wei1] | mask[wei2] | mask[wei3]) != need ) continue;
				for( int wei4 = 0 ; wei4 < 256 ; wei4++ )
				if( good[wei4] ){
					int nowwei[15] , top = 1;
					//if( wei4 == 197  &&  len[wei1] == 2 ) cout << "Num " << wei1 << "  wei2: " << weis[wei1][2] << endl;
					for( int i = 3-len[wei1]+1 ; i <= 3 ; i++ ) nowwei[top++] = weis[wei1][i];
					for( int i = 3-len[wei2]+1 ; i <= 3 ; i++ ) nowwei[top++] = weis[wei2][i];
					for( int i = 3-len[wei3]+1 ; i <= 3 ; i++ ) nowwei[top++] = weis[wei3][i];
					for( int i = 3-len[wei4]+1 ; i <= 3 ; i++ ) nowwei[top++] = weis[wei4][i];
					bool ok = 1;
					for( int i = 1 , j = top-1 ; i < top && j >= 1 ; i++,j-- ){
						if( nowwei[i] != nowwei[j] ){
							ok = 0;
							break;
						}
					}
					if( !ok ) continue;
					/*
					int pos = 1;
					for( int i= 1 ; i <= len[wei1] ; i++,pos++ )
						cout << nowwei[pos];
					cout << "|";
					for( int i= 1; i <= len[wei2] ; i++,pos++ )
						cout << nowwei[pos];
					cout << "|";
					for( int i= 1; i <= len[wei3] ; i++,pos++ )
						cout << nowwei[pos];
					cout << "|";
					for( int i= 1; i <= len[wei4] ; i++,pos++ )
						cout << nowwei[pos];
					cout << endl;
					*/
					sprintf( cs , "%d.%d.%d.%d\n" , wei1 , wei2 , wei3 , wei4 );
					s = string( cs );
					ans.pb(s);
				}
			}
	printf( "%d\n" , ans.size() );
	for( uint i = 0 ; i < ans.size() ; i++ )
		cout << ans[i];
	
	return 0;
}