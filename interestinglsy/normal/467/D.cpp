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
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(1e9))
#define LINF ((int)(1e18))
#define fir for( int i = 1 ; i <= n ; i++ )
#define fjr for( int j = 1 ; j <= n ; j++ )
#define fkr for( int k = 1 ; k <= n ; k++ )
#define firx( _x ) for( int i = 1 ; i <= _x ; i++ )
#define fjrx( _x ) for( int j = 1 ; j <= _x ; j++ )
#define fkrx( _x ) for( int k = 1 ; k <= _x ; k++ )
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
#define MAXN 100200

int n , m;

map< string , int > si;
string is[MAXN*5];
map< string , int > app;	//
vc< string > words;

/******************** D e b u g   C o n t r o l  C e n t e r ******************/
#define _SHOW_ 								0
#define _SHOW_GRAPH_ 	( _SHOW_ &			0		)
#define _SHOW_BASIC_ 	( _SHOW_ &			0 		)
#define _SHOW_SCC_	 	( _SHOW_ &			1 		)
#define _SHOW_TOPO_ 	( _SHOW_ &			1 		)
#define _SHOW_DP_ 		( _SHOW_ &			1 		)
/*************************** B A S I C ****************************/
void tui( string &s ){
	int len = s.length();
	for( int i = 0 ; i < len ; i++ )
		if( s[i] >= 'A'  &&  s[i] <= 'Z' )
			s[i] = s[i] - 'A' + 'a';
}
int countr( string s ){
	int len = s.length();
	int ret = 0;
	for( int i = 0 ; i < len ; i++ )
		if( s[i] == 'r' )
			ret++;
	return ret;
}

pii r[MAXN*5];
int nowid_addid = 1;

void addid( string s ){
	bool in = 0;
	if( si.count( s ) ){
		app[s]++;
		in = 1;
	}else{
		is[nowid_addid] = s;
		si[s] = nowid_addid;
		app[s] = 1;
	}
	if( in ) return;

	r[nowid_addid] = mp( countr( s ) , s.length() );

	nowid_addid++;
}

int ansr;
ll anslen;

/*************************************** S C C ************************************************/
vc<int> e[MAXN*5] , re[MAXN*5];
bool vis[MAXN];
vc<int> order;
void dfs( int pos ){
	vis[pos] = 1;
	for( uint i = 0 ; i < e[pos].size() ; i++ )
		if( !vis[e[pos][i]] )
			dfs( e[pos][i] );
	order.pb( pos );
}

int scc[MAXN];
//scc:i

void rdfs( int pos , int col ){
	vis[pos] = 1;
	scc[pos] = col;
	for( uint i = 0 ; i < re[pos].size() ; i++ )
		if( !vis[re[pos][i]] )
			rdfs( re[pos][i] , col );
}

int scc_cnt;
void getscc(){
	ms( vis ); order.clear();
	for( int i = 1 ; i <= nowid_addid ; i++ )
		if( !vis[i] )
			dfs( i );
	scc_cnt = 0;
	ms( vis );
	for( int i = order.size()-1 ; i >= 0 ; i-- ){
		if( !vis[order[i]] )
			rdfs( order[i] , scc_cnt++ );
	}
	scc_cnt--;
}
/*************************************** T O P O ************************************************/
vc<int> newe[MAXN*5];	//newe[i][j] = x:ix
int rudu[MAXN*5];		//
int topo_nowtime;
vc<int> topo;	//TOPO
void topo_dfs( int pos ){
	vis[pos] = 1;
	for( uint i = 0 ; i < newe[pos].size() ; i++ )
		if( !vis[ newe[pos][i] ] )
			topo_dfs( newe[pos][i] );
	topo.pb( pos );
}
void gettopo(){
	if( _SHOW_TOPO_ )
		cout << "\n[GetTopo]\n";

	ms( vis );
	topo.clear();
	firx( scc_cnt )
		if( !vis[i] ){
			if( _SHOW_TOPO_ )
				cout << "Start to dfs from " << i << endl;
			topo_dfs( i );
		}
	reverse( topo.begin() , topo.end() );
}
/*************************************** D P ************************************/
pii operator+( pii p1 , pii p2 ){
	int firs = p1.F + p2.F;
	int sec = p1.S + p2.S;
	return mp( firs , sec );
}
pii dp[MAXN*5];
pii scc_min[MAXN*5];
//scc_mini""
void getdp(){
	if( _SHOW_DP_ )
		cout << "\n[GetDP]\n";

	//DP:
	for( int i = 1 ; i <= scc_cnt ; i++ )
		dp[i] = scc_min[i];

	for( int i = 0 ; i < scc_cnt ; i++ ){
		int nowpos = topo[i];
		if( _SHOW_DP_ )
			cout << "Dealing with scc " << nowpos << endl;
		for( uint j = 0 ; j < newe[nowpos].size() ; j++ ){
			mymin( dp[ newe[nowpos][j] ] , dp[nowpos] );
		}
	}

	if( _SHOW_DP_ ){
		cout << "\n[Finally]\n";
		for( int i = 1 ; i <= scc_cnt ; i++ )
			cout << "The min val of scc " << i << " is ( " << dp[i].F << " , " << dp[i].S << " )\n";
	}

	for( int i = 1 ; i <= n ; i++ ){
		ansr += dp[ scc[ si[words[i]] ] ].F;
		anslen += dp[ scc[ si[words[i]] ] ].S;
	}
}
/*************************************** S O L V E ************************************************/

void solve(){
	//Get the scc and the max value in each scc
	getscc();

	for( int i = 1 ; i <= scc_cnt ; i++ )
		scc_min[i] = mp( INF , INF );
	for( int i = 1 ; i <= nowid_addid ; i++ )
		mymin( scc_min[ scc[i] ] , r[ i ] );

	if( _SHOW_SCC_ ){
		cout << "\n[Scc]\n";
		for( int i = 1 ; i < nowid_addid ; i++ )
			cout << i << " is in " << scc[i] << endl;
		cout << "There are(is) " << scc_cnt << " scc(s)\n";
		cout << "\n[SccMin]\n";
		for( int i = 1 ; i <= scc_cnt ; i++ )
			cout << "The min val in scc " << i << " is ( " << scc_min[i].F << " , " << scc_min[i].S << " )\n";
	}

	//Create a new Graph
	for( int i = 1 ; i <= nowid_addid ; i++ ){
		for( uint j = 0 ; j < e[i].size() ; j++ )
			if( scc[i] != scc[ e[i][j] ] )
				newe[ scc[i] ].pb( scc[ e[i][j] ] );
	}

	if( _SHOW_GRAPH_ ){
		cout << "\n[New Graph]\n";
		for( int i = 1 ; i <= scc_cnt ; i++ ){
			cout << i << "   |   ";
			for( uint j = 0 ; j < newe[i].size() ; j++ )
				cout << newe[i][j] << " ";
			cout << endl;
		}
	}

	//Get topo sequence
	gettopo();

	if( _SHOW_TOPO_ ){
		cout << "\n[Topo Seq]\n";
		for( uint i = 0 ; i < topo.size() ; i++ )
			cout << topo[i] << " ";
		cout << endl;
	}

	//Use DP to get the answer
	getdp();
}
/********************* M A I N *************************/
int main(){
	#ifndef ONLINE_JUDGE
		fin( "essay.txt" );
	#endif
	fastio;
	ansr = 0;
	anslen = 0LL;

	words.pb("0");
	cin >> n;
	fir{
		string a;
		cin >> a;
		tui( a );
		words.pb( a );
		addid( a );
	}

	cin >> m;
	firx( m ){
		string a , b;
		cin >> a >> b;
		tui( a ); tui( b );
		if( a == b ) continue;
		addid( a );
		addid( b );
	//	e[ si[a] ].pb( si[b] );
		e[ si[b] ].pb( si[a] );
		re[ si[a] ].pb( si[b] );
	}

	if( _SHOW_BASIC_ ){
		cout << "\n[ID]\n";
		for( int i = 1 ; i < nowid_addid ; i++ ){
			cout << i << " " << is[i] << endl;
		}
	}

	if( _SHOW_GRAPH_ ){
		cout << "\n[Normal Graph]\n";
		for( int i = 1 ; i < nowid_addid ; i++ ){
			cout << i << "   |   ";
			for( uint j = 0 ; j < e[i].size() ; j++ )
				cout << e[i][j] << " ";
			cout << endl;
		}

		cout << "\n[Reversed Graph]\n";
		for( int i = 1 ; i < nowid_addid ; i++ ){
			cout << i << "   |   ";
			for( uint j = 0 ; j < re[i].size() ; j++ )
				cout << re[i][j] << " ";
			cout << endl;
		}
	}

	solve();

	if( _SHOW_ )
		cout << endl << endl;

	cout << ansr << " " << anslen << endl;

	return 0;
}