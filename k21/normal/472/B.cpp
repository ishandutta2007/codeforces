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

int N, K;
int F[3000];

int main() {
	scanf("%d%d", &N, &K);
	
	REP(i,N) {
		scanf("%d", F+i);
	}
	
	sort(F, F+N);
	reverse(F, F+N);
	
	int total = 0;
	
	for (int i = 0; i < N; i += K) {
		total += 2*F[i]-2;
	}
	
	printf("%d\n", total);
	
	return 0;
}