#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

#define ll long long
#define x first
#define y second
typedef pair < int, int > point;
const int MaxN = 100100;
vector < point > v[MaxN];
vector < point > queries[MaxN];

int ispis[MaxN];
int sol[MaxN];
int a[MaxN];
int n, m;
queue <int> Q[MaxN];
int mp[MaxN], last[MaxN];

//logoritamska
int get( int x ) {
	x = MaxN - x - 1;
	int ret = 0;
	while( x>0 ) {
		ret += sol[x];
		x -= x& - x;
	}
	return ret;
}
void update( int x, int val ) {
	x = MaxN - x - 1;
	while( x < MaxN ) {
		sol[x] += val;
		x += x& - x;
	}
}


void solve() {

	for( int i=1; i<=n; i++ ) {

		for( int j=0; j<v[i].size(); j++ ) {
			int val = v[i][j].y;
			int l = v[i][j].x;
			int r = i;

			if( mp[val] ) {
				update( mp[val], -2 );
				if( last[val] )
					update( last[val], 1 );
				last[val] = mp[val];
			}
			mp[val] = l;
			update( l, 1 );
		}
		for( int j=0; j<queries[i].size(); j++ ) {
			int ind = queries[i][j].y;
			int val = queries[i][j].x;
			ispis[ind] = get( val );
		}
	}
}

int main() {

	cin >> n >> m;

	for( int i=1; i<=n; i++ ) {
		int x; cin >> x;
		if( x>n ) continue;
		Q[x].push( i );
		if( Q[x].size() == x ) {
			v[i].push_back( point( Q[x].front(), x ) );
			Q[x].pop();
		}
	}

	for( int i=1; i<=m; i++ ) {
		int x, y;
		cin >> x >> y;
		queries[y].push_back( point ( x, i ) );
	}
	solve();
	for( int i=1; i<=m; i++ ) cout << ispis[i] << endl;
	return 0;
}