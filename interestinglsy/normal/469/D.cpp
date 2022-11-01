#include <unordered_map>
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
#define MAXN 100100

unordered_map<int,int> index;
int inp[MAXN];
int n , a , b ;

int dsu[MAXN];
void init(){
	for( int i = 1 ; i <= n+2 ; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( pos == dsu[pos] ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}
void unite( int a , int b ){
	a = getfa(a);
	b = getfa(b);
	dsu[a] = b;
}
bool same( int a , int b ){
	return getfa(a) == getfa(b);
}

void NO(){
	out "NO\n";
	exit(0);
}

//n+1:
int main(){
	//fin("two_set.txt");
	in n; in a; in b;
	for( int i = 1 ; i <= n ; i++ ){
		in inp[i];
		index[inp[i]] = i;
	}
	init();
	//n+1:!A
	//n+2:!B
	for( int i = 1 ; i <= n ; i++ ){
		int pos = index[inp[i]];
		if( index.count(a-inp[i]) )
			unite( pos , index[a-inp[i]] );
		else
			unite( n+1 , pos );
		if( index.count(b-inp[i]) )
			unite( pos , index[b-inp[i]] );
		else
			unite( n+2 , pos );
	}
	if( same(n+1,n+2) ) NO();
	out "YES\n";
	for( int i = 1; i <= n ; i++ ){
		if( getfa(i) == getfa(n+1) )
			out "1 ";
		else out "0 ";
	}
	out endl;
	return 0;
}