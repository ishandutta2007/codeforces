// CF 553C
// POJ 2492
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
#define INF (1e9)
#define in cin >>
#define LINF (1e18)
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
#define MAXN 300100

int n , m , q;

int div2( int x ){
	if( x % 2 == 0 ) return x / 2;
	return x / 2 + 1;
}

int dsu[MAXN];
int longest[MAXN];
void init(){
	for( int i = 1 ; i <= n ; i++ ){
		dsu[i] = i;
		longest[i] = 0;
	}
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}
void unite( int a , int b ){
	//cout << a << " " << b << "  =>  ";
	a = getfa( a );
	b = getfa( b );
	if( a == b ) return;
	int o = div2( longest[b] ) + div2( longest[a] ) + 1;
	longest[a] = max(  max( o , longest[a] ) , longest[b]  );
	//cout << a << " " << b << " " << longest[a] << endl;
	dsu[b] = a;
}

vector<int> e[MAXN];
int maxd , maxpos;
void getmaxd( int pos , int fa , int deep ){
	if( deep > maxd ){
		maxd = deep;
		maxpos = pos;
	}
	for( uint i = 0 ; i < e[pos].size() ; i++ )
		if( e[pos][i] != fa )
			getmaxd( e[pos][i] , pos , deep+1 );
}
int getdiam( int pos ){
	//cout << "[Getdiam] " << pos << endl;
	maxd = -1;
	getmaxd( pos , -1 , 0 );
	int st = maxpos;
	//cout << maxpos << endl;
	maxd = -1;
	getmaxd( st , -1 , 0 );
	return maxd;
}

int main(){
	//fin("civ.txt");
	srand(time(0));
	
	read(n); read(m); read(q);
	init();
	
	for( int i = 1 ; i <= m ; i++ ){
		int a , b;
		read2(a,b);
		e[a].pb(b);
		e[b].pb(a);
		dsu[getfa(a)] = getfa(b);
	}
	
	for( int i = 1 ; i <= n ; i++ )
		if( dsu[i] == i )
			longest[i] = getdiam( i );
	
	for( int qi = 1 ; qi <= q ; qi++ ){
		int cmd , arg1 , arg2;
		read2(cmd,arg1);
		if( cmd == 1 ){
			printf( "%d\n" , longest[getfa(arg1)] );
		}else{
			read(arg2);
			if( rand()%2 ) swap( arg1 , arg2 );
			unite( arg1 , arg2 );
		}
	}
	
	return 0;
}