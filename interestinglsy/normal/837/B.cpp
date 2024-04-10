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
#define MAXN 200

int data[MAXN][MAXN];
int n , m;
int heng[MAXN],zong[MAXN];

int main(){
//	fin("B.txt");
	ms(heng); ms(zong);
	read2( n , m );
	bool hengsame=1 , zongsame=1;
	bool app1=0 , app2=0 , app3=0;
	for( int i = 1; i <= n ; i++ )	
		for( int j = 1 ; j <= m ; j++ ){
			char x;
			cin >> x;
			if( x == 'R' ){
				data[i][j] = 1;
				app1 = 1;
			}
			else if( x == 'G' ){
				data[i][j] = 2;
				app2 = 1;
			}
			else if( x == 'B' ){
				data[i][j] = 3;
				app3 = 1;
			}
			else{
				printf("NO\n");//cout << x << endl;
				return 0;
			}
			if( i == 1 ) heng[j] = data[i][j];
			else
				if(heng[j] != data[i][j])
					hengsame = 0;
			if( j == 1 ) zong[i] = data[i][j];
			else
				if(zong[i] != data[i][j])
					zongsame = 0;
		}
	if( !hengsame  &&  !zongsame ){
		printf("NO\n");//cout << "1" << endl;
		return 0;
	}
	if( !(app1&&app2&&app3) ){
		printf("NO\n");
		return 0;
	}
	swap( hengsame , zongsame );
	//cout << hengsame << " " << zongsame << endl;
	if( hengsame ){
		int last = -1 , chg = 0 , w = 1 , lastw;
		for( int i = 1 ; i <= n ; i++ ){
			if( zong[i] != last ){
				last = zong[i];
				chg++;
				if( lastw != w  &&  chg != 1  &&  chg != 2 ){
					//cout << i << endl;
					printf("NO\n");
					return 0;
				}
				lastw = w;
				w = 1;
			}else{
				w++;
			}
			//cout << i << " " << last << " " << chg << " " << w << " " << lastw << endl;
		}
		if( chg == 3  &&  w == lastw ) printf("YES\n");
		else printf("NO\n");
	}else{
		int last = -1 , chg = 0 , w = 1 , lastw;
		for( int i = 1 ; i <= m ; i++ ){
			if( heng[i] != last ){
				last = heng[i];
				chg++;
				if( lastw != w  &&  chg != 1  &&  chg != 2 ){
					//cout << i << endl;
					printf("NO\n");
					return 0;
				}
				lastw = w;
				w = 1;
			}else{
				w++;
			}
			//cout << i << " " << last << " " << chg << " " << w << " " << lastw << endl;
		}
		if( chg == 3  &&  w == lastw) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}