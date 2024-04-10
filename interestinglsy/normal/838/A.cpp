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
#define MAXN 5555
#define PCNT 367

int n , m;
bool data[MAXN][MAXN];
int sum[MAXN][MAXN];
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2477,2477};

int getsum( int ux , int uy , int dx , int dy ){
	//cout << "getsum: " << uy << " " << ux << "   " << dy << " " << dx << endl;
	//cout << "is: " << sum[dy][dx] - sum[uy-1][dx] - sum[dy][ux-1] + sum[uy-1][ux-1] << endl;
	return sum[dy][dx] - sum[uy-1][dx] - sum[dy][ux-1] + sum[uy-1][ux-1];
}
int main(){
//	fin( "A.txt" );
	ms( data ); ms( sum );
	fastio;
	
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ){
			char x;
			cin >> x;
			if( x == '1' ) data[i][j] = 1;
			else data[i][j] = 0;
		}
	
	for( int i = 1 ; i < MAXN ; i++ )
		for( int j = 1 ; j < MAXN ; j++ )
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + data[i][j];
	/*
	for( int i = 1 ; i <= m ; i++ ){
		for( int j = 1 ; j <= m ; j++ )
			cout << sum[i][j] << " ";
		cout << endl;
	}
	//return 0;
	*/
	int ans = INF;
	for( int i = 0 ; i < PCNT ; i++ ){
		int nowp = primes[i];
		//cout << "-----------------Newk------------\n";
		//cout << "Now k is " << nowp << endl;
		int nowans = 0;
		for( int y = nowp ; y-nowp <= n ; y += nowp )
			for( int x = nowp ; x-nowp <= m ; x += nowp ){
				//cout << "At x: " << x << "   y: " << y << "  Need to chg: ";
				int cnt1 = getsum( x-nowp+1 , y-nowp+1 , x , y );
				int cnt2 = nowp * nowp - cnt1;
				nowans += min( cnt1 , cnt2 );
				//cout << min( cnt1 , cnt2 ) << endl;
			}
		//cout << "Ans is " << nowans << endl;
		ans = min( ans , nowans );
		if( nowp > n  &&  nowp > m ) break;
	}
	
	cout << ans << endl;
	
	return 0;
}