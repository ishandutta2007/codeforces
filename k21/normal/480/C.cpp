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
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 5500;
const int MAXK = 5500;
const ll MOD = 1000000007;

int N, K, A, B;

ll t1[MAXN];
ll t2[MAXN];

ll* curr = t1;
ll* nxt = t2;

int main() {
	scanf("%d%d%d%d", &N, &A, &B, &K);
	--A; --B;
	
	REP(i,N) curr[i] = 1;
	curr[B] = 0;
	
	REP(k,K) {
		curr[N] = 0;
		ll sum = 0;
		REP(i,N+1) {
			ll c = curr[i];
			curr[i] = sum;
			sum += c;
			if (sum >= MOD) sum -= MOD;
		}
		REP(x,N) {
			int y1 = B;
			int y2 = 2*x-B;
			if (B < x) {
				++y1; --y2;
			} else {
				--y1; ++y2;
			}
			if (y2 < 0) y2 = 0;
			else if (y2 >= N) y2 = N-1;
			int ymin = min(y1, y2);
			int ymax = max(y1, y2) + 1;
			ll p1 = curr[ymax] - curr[ymin];
			if (p1 < 0) p1 += MOD;
			else if (p1 >= MOD) p1 -= MOD;
			ll p2 = curr[x+1] - curr[x];
			if (p2 < 0) p2 += MOD;
			else if (p2 >= MOD) p2 -= MOD;
			p1 -= p2;
			if (p1 < 0) p1 += MOD;
			nxt[x] = p1;
		}
		swap(curr, nxt);
	}
	
	printf("%d\n", (int)(curr[A] % MOD));
	
	return 0;
}