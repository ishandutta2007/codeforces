#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

int main() {
	ll x, y, m;
	cin >> x >> y >> m;
	ll gr = max(x, y), sm = min(x, y);
	if (gr >= m) {
		cout << "0\n";
		return 0;
	}
	if (gr <= 0) {
		cout << "-1\n";
		return 0;
	}
	ll r = 0;
	while (sm+gr < 0) {
		ll mul = 1;
		while (sm+mul*gr < 0) mul *= 2;
		mul /= 2;
		r += mul;
		sm += mul*gr;
	}
	while (gr < m) {
		sm += gr;
		if (sm > gr) swap(sm, gr);
		++r;
		if (gr <= 0) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << r << '\n';
	return 0;
}