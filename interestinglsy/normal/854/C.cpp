#include <assert.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define dq deque
#define vc vector
#define INF ((int)(2e9))
#define LINF ((int)(1e18))
#define out cout <<
#define ln  << endl
#define pb push_back
#define mp make_pair
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define sint short int
#define ull unsigned long long
#define pq priority_queue
#define pii pair<int,int>
#define uint unsigned int
#define ll long long
#define B out "BreakPoint\n";
#define read(_nowans) scanf("%d",&_nowans)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_nowans1,_nowans2) scanf("%d %d",&_nowans1,&_nowans2)
#define msn(_data,_nowans) memset(_data,_nowans,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_nowans1,_nowans2,_nowans3) scanf("%d %d %d",&_nowans1,&_nowans2,&_nowans3)
#define lb( _x , _y ) ( lower_bound( _x.begin() , _x.end() , _y ) - _x.begin() + 1 )
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print( ll _x ){ printf("%I64d\n",_x); }
_tp<_tyn T>void print( T _data[] , int _size ){
	for( int i = 1 ; i <= _size ; i++ )
		cout << _data[i] << " ";
	cout << endl;
}
#define MAXN 300010
#define PII pii
#define QII pii

int n,k;
queue< QII >  q1;
pq< PII , vector<PII> , less<PII> >  q2;
int ti[MAXN];
ll ans = 0LL;

int main(){
//	fin("C.txt");

	read2(n,k);
	for( int i = 1 ; i <= n ; i++ ){
		int x;
		read(x);
		q1.push(mp(i,x));		///(ll)x*(ll)(k+n+n-i)
	}

	/*
	for( int i = 1 ; i <= n ; i++ ){
		cout << i << " :  " << " id: " << q1.top().F.F << " cost: " << q1.top().F.S << " Xdcost: " << q1.top().S << endl;
		q1.pop();
	}
	return 0;
	*/

	for( int t = k+1 ; t <= k+n ; t++ ){
		while( !q1.empty()  &&  q1.front().F <= t ){
			q2.push( mp( q1.front().S , q1.front().F ) );
			q1.pop();
		}
		if( q2.empty() ){
			//cout << "Empty! " << t << endl;
			continue;
		}
		//cout << q2.size() << endl;
		PII now = q2.top();
		q2.pop();
		ans += (ll)now.F * (ll)( t - now.S );
		ti[now.S] = t;
		//cout << "Now: " << now.S.S << endl;
	}

	print(ans);
	print(ti,n);

	return 0;
}