#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define INF (1e+8)
#define LINF 9999999999999999
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define lb lower_bound
#define ub upper_bound
using namespace std;
#define MAXN 200100

int n,m,k;
int color[MAXN];

int dsu[MAXN];
void init(){
	for( int i = 1; i <= n; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	dsu[pos] = getfa( dsu[pos] );
	return dsu[pos];
}
void merge( int a , int b ){
	a = getfa( a ); b = getfa( b );
	if( a != b )
		dsu[a] = b;
}
vector<int> lian[MAXN];
bool vis[MAXN];

int main(){
	//freopen("C.txt","r",stdin);
	
	scanf("%d %d %d",&n,&m,&k);
	init(); ms(vis);
	for( int i = 1; i <= n; i++ )
		scanf("%d",&color[i]);
	for( int i = 1; i <= m; i++ ){
		int a , b;
		scanf("%d %d",&a,&b);
		merge( a , b );
		vis[a] = vis[b] = 1;
	}
	
	for( int i = 1; i <= n; i++ ){
		lian[ getfa(i) ].pb( color[i] );
	}
	
	int ans = 0;
	for( int i = 1; i <= n ; i++ ){
		if( getfa(i) == i  &&  vis[i] ){
			sort( lian[i].begin() , lian[i].end() );
			int maxapp = 1 , app = 1;
			for(uint j = 1; j < lian[i].size(); j++ ){
				if( lian[i][j] == lian[i][j-1] ){
					app++;
					maxapp = max( app , maxapp );
				}
				else{
					app = 1;
					maxapp = max( app , maxapp );
				}
			}
			ans += lian[i].size() - maxapp;
		}
	} 
		
	printf("%d\n",ans);
	
	return 0;
}