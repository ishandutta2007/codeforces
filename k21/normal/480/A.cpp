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

const int MAXN = 6000;

int N;
pair<int, int> A[MAXN];

int main() {
	scanf("%d", &N);
	REP(i,N) {
		int a, b;
		scanf("%d%d", &a, &b);
		A[i] = {a, b};
	}
	sort(A, A+N);
	
	int r = 0;
	REP(i,N) {
		if (A[i].second >= r) {
			r = A[i].second;
		} else {
			r = A[i].first;
		}
	}
	
	printf("%d\n", r);
	
	return 0;
}