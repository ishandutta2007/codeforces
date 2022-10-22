#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MaxN = 100100;

multiset<int> ms;
multiset<int>::iterator it;
int where[MaxN];
int n, sol;
int b[MaxN];

void solve() {
	for( int i=0; i<n; i++ ) {

		it = ms.upper_bound( i );
		sol = *it - i;
		it--;
		sol = min( sol, abs( *it - i ) );

		ms.erase( ms.lower_bound( i - where[ b[i] ] ) );
		ms.insert( n - where[ b[i] ] + i );

		cout << sol << endl;
	}
}

int main() {

	cin >> n;

	for( int i=0; i<n; i++ ) {
		int x;
		cin >> x;
		where[ x ] = i;
	}
	for( int i=0; i<n; i++ ) {
		cin >> b[i];
		ms.insert( i - where[ b[i] ] );
	}

	solve();
	return 0;
}