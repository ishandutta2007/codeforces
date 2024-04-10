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
#define A +n
#define MOD (1e9+7)

int n,m;
int dsu[MAXN*2];
void init(){
	for( int i = 1 ; i <= n+n ; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}
bool unite( int a,  int b ){
	a = getfa(a);
	b = getfa(b);
	if( a == b )
		return 0;
	dsu[a] = b;
	return 1;
}

int main(){
	//fin("love.txt");
	
	read2( n , m );
	init();
	for( int i = 1 ; i <= m ; i++ ){
		int cmd , a , b;
		read3( a , b , cmd );
		if( cmd ){
			unite( a , b );
			unite( a A , b A );
			if( getfa(a A) == getfa(a) ){
				//cout << i << endl;
				printf("0\n");
				return 0;
			}
		}else{
			unite( a , b A );
			unite( a A , b );
			if( getfa(a A) == getfa(a) ){
				//cout << i << endl;
				printf("0\n");
				return 0;
			}
		}
	}
	
	int cnt = 0;
	int ans = 1;
	for( int i = 1 ; i <= n ; i++ )
		if( getfa(i) == i )
			cnt++;
	for( int i = 1 ; i < cnt ; i++ ){
		ans *= 2;
		if( ans >= MOD ) ans -= MOD;
	}
	ans %= (1000000007);
	printf("%d\n",ans);
	
	return 0;
}