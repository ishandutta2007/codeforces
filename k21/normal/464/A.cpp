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

const int MAXP = 30;
const int MAXN = 1100;

int N, P;
char S[MAXN];

int main() {
	scanf("%d%d ", &N, &P);
	gets(S+2);
	REP(i,N) S[i+2] -= 'a';
	S[0] = S[1] = -1;
	
	int i = N+2;
	while (i > 2) {
		++S[i-1];
		while (S[i-1] == S[i-2] || S[i-1] == S[i-3]) ++S[i-1];
		if (S[i-1] < P) break;
		--i;
	}

	if (i <= 2) {
		printf("NO\n");
		return 0;
	}
	
	while (i < N+2) {
		S[i] = 0;
		while (S[i] == S[i-1] || S[i] == S[i-2]) ++S[i];
		if (S[i] >= P) {
			printf("NO\n");
			return 0;
		}
		++i;
	}

	REP(i,N) S[i+2] += 'a';

	printf("%s\n", S+2);
	
	return 0;
}