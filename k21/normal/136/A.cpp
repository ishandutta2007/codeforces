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

#define DEBUG(x) cout << '>' << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

using namespace std;

int n;
int perm[120];
int res[120];

int main() {
	scanf("%d", &n);
	REP(i,n) {scanf("%d", perm+i); --perm[i];}
	REP(i,n) res[perm[i]] = i;
	REP(i,n) printf((i==n-1)?"%d\n":"%d ", res[i]+1);
	return 0;
}