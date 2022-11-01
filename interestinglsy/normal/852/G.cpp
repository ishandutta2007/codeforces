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
#define mp make_pair
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
#define MAXN 200100
using namespace std;

struct Node{
	int isword;
	Node *son[6];
	int vis;
	void init(){
		for( int i = 0 ; i < 5 ; i++ )
			son[i] = NULL;
		isword = 0;
		vis = 0;
	}
};

Node *root;
inline void newword(){
	Node *pos = root;
	while(1){
		int nowlet = getchar()-'a';
		if( nowlet + 'a' == '\n' ) break;
		if( !( pos->son[nowlet] ) ){
			pos->son[nowlet] = new Node;
			pos->son[nowlet]->init();
		}
		pos = pos->son[nowlet];
	}
	pos->isword++;
}

vc<char> nowword;
inline void print( Node *pos ){
	if( pos->isword ){
		for( uint i = 0 ; i < nowword.size() ; i++ )
			cout << nowword[i];
		cout << "\t\t x" << pos->isword;
		cout << endl;
	}
	for( int i = 0 ; i < 5 ; i++ )
		if( pos->son[i] ){
			nowword.pb(i+'a');
			print( pos->son[i] );
			nowword.pop_back();
		}
}

char nows[100010];
int ans,len;
inline void solve( Node *pos , int ptr , int t ){
	//cout << nows << " " << ptr << endl;
	if( ptr == len ){
		//cout << pos->isword << endl;
		if( pos->vis != t ) ans += pos->isword;
		pos->vis = t;
		return;
	}
	int nowlet = nows[ptr]-'a';
	if( nows[ptr] != '?' ){
		if( !( pos->son[nowlet] ) ) return;
		solve( pos->son[nowlet] , ptr+1 , t );
		return;
	}
	solve( pos , ptr+1 ,t );
	for( int i = 0 ; i < 5 ; i++ )
		if( pos->son[i] )
			solve( pos->son[i] , ptr+1 , t );
}

int n,m;

int main(){
//	fin( "G.txt" );
	root = new Node;
	root->init();

	read2(n,m);
	getchar();

	for( int i = 1 ; i <= n ; i++ ){
		newword();
	}

	for( int i = 1 ; i <= m ; i++ ){
		scanf("%s",nows);
		ans = 0;
		len = strlen(nows);
		solve( root , 0 , i );
		printf("%d\n",ans);
	}

	return 0;
}