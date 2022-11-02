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

int N;
int len;
int arr[1<<21];
int earr[1<<21];
int Q;

ll invCounts[30];
ll sameCounts[30];

void countInv(int lvl, int i) {
	if (lvl == 0) {
		return;
	}
	ll here = 0;

	countInv(lvl-1, i*2);
	countInv(lvl-1, i*2+1);

	int at = -1;
	int atCnt1 = 0;
	int atCnt2 = 0;

	int f1 = i * (1 << lvl);
	int f2 = (2*i+1) * (1 << (lvl-1));
	int t = f1;
	const int e1 = f2;
	const int e2 = 2*f2 - f1;
	const int b1 = f1;

	while (f1 < e1 || f2 < e2) {
		int sel;
		if (f1 < e1 && f2 < e2) {
			if (arr[f1] < arr[f2]) {
				sel = 1;
			} else if (arr[f2] < arr[f1]) {
				sel = 2;
			} else {
				sel = 1;
			}
		} else if (f1 < e1) {
			sel = 1;
		} else {
			sel = 2;
		}

		if (sel == 1) {
			earr[t++] = arr[f1++];
		} else {
			here += e1 - f1;
			earr[t++] = arr[f2++];
		}
		if (earr[t-1] != at) {
			sameCounts[lvl] += (ll)atCnt1 * atCnt2;
			at = earr[t-1];
			atCnt1 = 0;
			atCnt2 = 0;
		}
		if (sel == 1) ++atCnt1;
		else ++atCnt2;
	}

	sameCounts[lvl] += (ll)atCnt1 * atCnt2;

	FOR(j,b1,e2-1) {
		arr[j] = earr[j];
	}

	invCounts[lvl] += here;
}

int main() {
	scanf("%d", &N);
	len = 1<<N;
	REP(i,len) {
		int x;
		scanf("%d", &x);
		arr[i] = x;
	}

	countInv(N, 0);

	//REP(i,N+1) DEBUG(sameCounts[i]);

	scanf("%d", &Q);
	REP(i,Q) {
		int lvl;
		scanf("%d", &lvl);
		while (lvl) {
			ll parts = (1LL << (N-lvl));
			ll inPart = (1LL << (lvl-1)) * (1LL << (lvl-1));
			ll onLevel = parts * inPart;
			invCounts[lvl] = onLevel - sameCounts[lvl] - invCounts[lvl];
			--lvl;
		}
		ll sum = 0;
		REP(j,N+1) sum += invCounts[j];
		printf("%lld\n", sum);
	}
	return 0;
}