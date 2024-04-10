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

const int MAXN = 300100;

int N;
int A[MAXN];

int main() {
	scanf("%d", &N);
	REP(i,N) scanf("%d", A+i);

	sort(A, A+N);
	reverse(A, A+N);

	ll score = 0;
	ll sum = 0;

	REP(i,N) {
		sum += A[i];
		if (i != 0) {
			score += sum;
		}
	}

	score += sum;

	printf("%I64d\n", score);

	return 0;
}