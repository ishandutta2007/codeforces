#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
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
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const ll MOD = 1000000007LL;
const int MAX = 2100;

int n, k;
ll curr[MAX], nxt[MAX];

int main() {
	scanf("%d%d", &n, &k);

	FOR(i,1,n) curr[i] = 0;
	curr[1] = 1;
	REP(i,k) {
		FOR(j,1,n) nxt[j] = 0;
		FOR(j,1,n) {
			int m = j;
			while (m <= n) {
				nxt[m] += curr[j];
				m += j;
			}
		}
		FOR(j,1,n) {
			curr[j] = nxt[j] % MOD;
		}
	}

	ll sum = 0;
	FOR(i,1,n) sum += curr[i];
	sum %= MOD;
	printf("%lld\n", sum);
	return 0;
}