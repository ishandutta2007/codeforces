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
#define MAXN 510
#define MAXM 10010

int n , m , k ;
int a[MAXM] , b[MAXM];

class Dsu{
public:
	int dsu[MAXN];
	int cnt;
	void init(){
		for( int i = 1 ; i <= n ; i++ )
			dsu[i] = i;
		cnt = 0;
	}
	int getfa( int pos ){
		if( dsu[pos] == pos ) return pos;
		return dsu[pos] = getfa( dsu[pos] );
	}
	void unite( int a , int b ){
		a = getfa( a );
		b = getfa( b );
		if( a != b ){
			dsu[b] = a;
			cnt++;
		}
	}
};
Dsu pre[MAXM];
Dsu suf[MAXM];

int main(){
	//fin("conn.txt");
	fastio;
	
	in n; in m;
	
	for( int i = 0 ; i <= m+1 ; i++ ){
		pre[i].init();
		suf[i].init();
	}
	
	for( int i = 1 ; i <= m ; i++ ){
		in a[i]; in b[i];
	}
	
	pre[1].unite( a[1] , b[1] );
	suf[m].unite( a[m] , b[m] );
	for( int i = 2 , j = m-1 ; i <= m ; i++,j-- ){
		pre[i] = pre[i-1]; pre[i].unite( a[i] , b[i] );
		suf[j] = suf[j+1]; suf[j].unite( a[j] , b[j] );
	}
	
	in k;
	for( int q = 1 ; q <= k ; q++ ){
		int l , r;
		in l; in r;
		Dsu ans = pre[l-1];
		for( int i = 1 ; i <= n ; i++ )
			if( suf[r+1].dsu[i] != i )
				ans.unite( i , suf[r+1].dsu[i] );
		out (n - ans.cnt) ln;
	}
	
	return 0;
}