//76A
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
#define MAXN 200600
#define MAXLOG 12

int n , m;
int fro[MAXN] , too[MAXN];
ll cot[MAXN];
struct Edge{
	int from , to , id;
	ll cost;
	Edge( int fromm , int too , ll costt , int iid ){
		from = fromm;
		to = too;
		cost = costt;
		id = iid;
	}
};
bool operator<( Edge e1 , Edge e2 ){
	return e1.cost < e2.cost;
}
vector<Edge> g;

int dsu[MAXN];
void init(){
	for( int i = 0 ; i <= n+2 ; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}
bool unite( int a , int b ){
	//cout << a << " " << b << "    ";
	a = getfa(a);
	b = getfa(b);
	//cout << a << " " << b << endl;
	if( a == b ) return 0;
	dsu[a] = b;
	return 1;
}

ll mintreecost = 0;
vector<Edge> e[MAXN];
bool intree[MAXN];

void mintree(){
	sort( g.begin() , g.end() );
	ms( intree );
	for( int i = 0 ; i <= n ; i++ ) e[i].clear();
	init();
	int cnt = 0 , pos = 0;
	while( cnt < n-1 ){
		//if( pos >= m ) return;
		Edge now = g[pos];
		if( unite( now.from , now.to) ){
			//cout << "[mintree] Choose Edge " << now.id << endl;
			mintreecost += now.cost;
			cnt++;
			e[now.from].pb( Edge( 0 , now.to , now.cost , now.id ) );
			e[now.to].pb( Edge( 0 , now.from , now.cost , now.id ) );
			intree[now.id] = 1;
		}
		pos++;
	}
	//for( int i = 1 ; i <= n ; i++ )
	//	cout << cycid[i] << " ";
	//cout << endl;
	//for( int i = 1 ; i <= n ; i++ )
	//	cout << maxedge[i] << " ";
	//cout << endl;
	//cout << mintreecost << endl;
}

int par[MAXLOG][MAXN];
ll maxedge[MAXLOG][MAXN];	//maxedge[i][v]=x   MAXEDGE in [v,parent[i][v]]
int deep[MAXN];

void dfs( int pos , int fa , int d , ll lastcost ){
	deep[pos] = d;
	par[0][pos] = fa;
	maxedge[0][pos] = lastcost;
	for( uint i = 0 ; i < e[pos].size() ; i++ )
		if( e[pos][i].to != fa )
			dfs( e[pos][i].to , pos , d+1 , e[pos][i].cost );
}
void lca_init(){
	msn( deep , -1 );
	msn( maxedge , -1 );
	msn( par , -1 );
	dfs( 1 , -1 , 0 , -1 );
	for( int i = 0 ; i+1 < MAXLOG ; i++ )
		for( int j = 1 ; j <= n ; j++ ){
			if( par[i][j] < 0 ){
				par[i+1][j] = -1;
				maxedge[i+1][j] = maxedge[i][j];
			}else{
				par[i+1][j] = par[i][par[i][j]];
				maxedge[i+1][j] = max(  maxedge[i][j] , maxedge[i][par[i][j]]  );
			}
		}
	//for( int i = 1;  i <= n ; i++ ){
	//	int x = rand() % 3;
	//	cout << i << "  go up  2^" << x << "  =>  " << par[x][i] << endl;
	//}
}
ll getmaxdis( int a , int b ){
	ll ret = -1;
	if( deep[a] < deep[b] ) swap( a , b );
	int delta = deep[a] - deep[b];
	//cout << bitset<3>(delta) << endl;
	for( int i = 0 ; i < MAXLOG ; i++ ){
		if( delta == 0 ) break;
		if( delta & (1<<i) ){
			ret = max( ret , maxedge[i][a] );
			a = par[i][a];
		}
	}
	if( a == b ) return ret;
	//cout << a << " " << b << endl;
	for( int i = MAXLOG-1 ; i >= 0 ; i-- )
		if( par[i][a] != par[i][b] ){
			ret = max( ret , maxedge[i][a] );
			ret = max( ret , maxedge[i][b] );
			a = par[i][a];
			b = par[i][b];
		}
	ret = max( ret , maxedge[0][a] );
	ret = max( ret , maxedge[0][b] );
	//cout << "[Ret] " << ret << endl;
	return ret;
}

void solve(){
	//cout << "[ANS]\n";
	for( int i = 1 ; i <= m ; i++ ){
		if( intree[i] ){
			printf("%I64d\n",mintreecost);
			continue;
		}
		printf("%I64d\n", mintreecost - getmaxdis( fro[i] , too[i] ) + cot[i] );
	}
}

int main(){
//	fin("minimum.txt");
	g.clear();
	ms(fro); ms(too); ms(cot);
	
	read2( n , m );
	for( int i = 1 ; i <= m ; i++ ){
		int ff , tt;
		ll cc;
		read2( ff , tt );
		scanf("%I64d",&cc);
		g.pb( Edge( ff , tt , cc , i ) );
		fro[i] = ff;
		too[i] = tt;
		cot[i] = cc;
	}
	
	mintree();
	lca_init();
	//cout << getmaxdis( 2 , 5 ) << endl;
	solve();
	
	return 0;
}