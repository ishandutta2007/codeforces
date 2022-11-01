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
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%I64d ",_x);}

int n , m , q ;
string s , t;
bool good[26],bo;

int main(){
	//fin( "A.txt" );
	ms( good );

	cin >> s;
	n = s.length();
	for( int i = 0 ; i < n ; i++ )
		good[ s[i]-'a' ] = 1;

	cin >> s;
	n = s.length();

	cin >> q;
	for( int qi = 1 ; qi <= q ; qi++ ){
		cin >> t;
		m = t.length();

		int j = 0;
		bool wa = 0;
		for( int i = 0 ; i < n ; i++ ){
			if( j == m  &&  i != n-1  &&  s[i] != '*' ){
				wa = 1;
				break;
			}
			if( j == m  &&  i == n-1  &&  s[i] == '*' )break;
			if( s[i] == '?'  &&  !good[ t[j]-'a' ] ){
				wa = 1;
				break;
			}
			if( s[i] == '*' ){
				while( j <= m-1  &&  !good[ t[j]-'a' ]  &&  n-i <= m-j ) j++;
				j--;
			}
			if( s[i] != '?'  &&  s[i] != '*'  &&  s[i] != t[j] ){
				wa = 1;
				break;
			}
			j++;
		}
		if( !wa  &&  j >= m ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}