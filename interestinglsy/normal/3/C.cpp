#include <algorithm>
#include <iostream>
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
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(1e9))
#define in cin >>
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
_tp<_tyn T>void print(T _x){
for(auto _it=_x.begin();_it!=_x.end();_it++)
cout<<*_it<<" ";cout ln;}
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%lld ",_x);}

char nows[12];
map < int , string > m;

int getmask( int mask , int pos ){
	return (mask >> (pos*2)) & 3;
}
void printmask( int mask ){
	for( int i = 0 ; i < 9 ; i++ ){
		if( !getmask( mask , i ) ) cout << ".";
		else if( getmask( mask , i ) == 1 )cout<< "X";
		else if( getmask( mask , i ) == 2 ) cout << "0";
		else cout << getmask( mask , i );
		if( (i+1) % 3 == 0 ) cout << endl;
	}
}

string ok[] = { "012" , "345" , "678" , "036" , "147" , "258" , "048" , "246" };
bool ins( int mask ){
	for( int i = 0 ; i < 8 ; i++ ){
		if( getmask( mask , ok[i][0]-'0' ) == getmask( mask , ok[i][1]-'0' ) &&
			getmask( mask , ok[i][1]-'0' ) == getmask( mask , ok[i][2]-'0' ) &&
			getmask( mask , ok[i][2]-'0' )  )
			return 1;
	}
	return 0;
}
string opp( string x ){
	if( x == "first" ) return "second";
	return "first";
}
void dfs( int mask , int sign , string vec ){
	if( ins( mask ) ){
		m[mask] = "the " + opp( vec ) + " player won";
		return;
	}
	if( __builtin_popcount( mask ) == 9 ){
		m[mask] = "draw";
		return;
	}
	m[mask] = vec;
	for( int i = 0 ; i < 9 ; i++ ){
		if( !getmask( mask , i ) ){
			mask ^= sign << (i*2);
			dfs( mask , sign ^ 3 , opp(vec) );
			mask ^= sign << (i*2);
		}
	}
}

int main(){
//	fin("tic.txt");
	fastio;
	
	string inps;
	int inp = 0;
	for( int i = 0 ; i < 3 ; i++ ){
		inps.clear();
		cin >> inps;
		for( int j = 0 ; j < 3 ; j++ ){
			if( inps[j] == 'X' )
				inp |= ( 1 << (i*6 + j*2) );
			if( inps[j] == '0' )
				inp |= ( 2 << (i*6 + j*2) );
		}
	}
	//printmask( inp );
	dfs( 0 , 1 , "first" );
	
	if( m.find( inp ) == m.end() ){
		cout << "illegal\n";
	}else{
		cout << m[inp] << endl;
	}
	
	return 0;
}