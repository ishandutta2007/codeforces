#include <bits/stdc++.h>
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
#define mp make_pair
#define sint short int
#define ull unsigned long long
#define pq priority_queue
#define pii pair<int,int>
#define uint unsigned int
#define ll long long
#define B out "BreakPoint" ln;
#define read(_nowans) scanf("%d",&_nowans)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_nowans1,_nowans2) scanf("%d %d",&_nowans1,&_nowans2)
#define msn(_data,_nowans) memset(_data,_nowans,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define read3(_nowans1,_nowans2,_nowans3) scanf("%d %d %d",&_nowans1,&_nowans2,&_nowans3)
#define lb( _x , _y ) ( lower_bound( _x.begin() , _x.end() , _y ) - _x.begin() + 1 )
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print( int _x ){ printf("%d\n",_x); }
_tp<_tyn T>void print( T _data[] , int _size ){
	for( int i = 1 ; i <= _size ; i++ )
		cout << _data[i] << " ";
	cout << endl;
}
#define MAXN 100100

int n;

int inset[2];
vc<int> e[MAXN];
void dfs( int pos , bool in , int fa ){
	inset[in]++;
	for( uint i = 0 ; i < e[pos].size() ; i++ )
		if( e[pos][i] != fa )
			dfs( e[pos][i] , in^1 , pos );
}

int main(){
	ms(inset);

	read(n);
	for( int i = 1 ; i < n ; i++ ){
		int a,b;
		read2(a,b);
		e[a].pb(b);
		e[b].pb(a);
	}

	dfs(1,0,-1);

	ll ans = 0LL;
	ans += (ll)inset[0] * (ll)inset[1] - (ll)n + 1LL;

	printf("%I64d",ans);

	return 0;
}