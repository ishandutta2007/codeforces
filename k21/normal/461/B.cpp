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

const int MAXN = 101000;
const ll MOD = 1000000007;

int N;
int P[MAXN];
int C[MAXN];

vector<int> children[MAXN];

ll empty[MAXN];
ll full[MAXN];

ll pre[MAXN];
ll post[MAXN];

void dfs(int i) {
	if (children[i].empty()) {
		if (C[i]) {
			empty[i] = 0;
			full[i] = 1;
		} else {
			empty[i] = 1;
			full[i] = 0;
		}
		return;
	}

	for (int child : children[i]) {
		dfs(child);
	}

	ll e = 1;
	for (int child : children[i]) {
		e *= empty[child] + full[child];
		e %= MOD;
	}

	if (!C[i]) {
		empty[i] = e;
		int l = children[i].size();
		pre[0] = 1;
		FOR(j, 1, l-1) {
			int child = children[i][j-1];
			pre[j] = pre[j-1] * (full[child] + empty[child]);
			pre[j] %= MOD;
		}
		post[l-1] = 1;
		FORD(j, l-2, 0) {
			int child = children[i][j+1];
			post[j] = post[j+1] * (full[child] + empty[child]);
			post[j] %= MOD;
		}

		ll f = 0;
		REP(j,l) {
			int child = children[i][j];
			//DEBUG(j);
			//DEBUG(full[child]);
			//DEBUG(pre[j]);
			//DEBUG(post[j]);
			ll x = full[child];
			x *= pre[j];
			x %= MOD;
			x *= post[j];
			x %= MOD;
			f += x;
		}

		full[i] = f % MOD;
	} else {
		empty[i] = 0;
		full[i] = e;
	}

	//DEBUG(i);
	//DEBUG(empty[i]);
	//DEBUG(full[i]);
}

int main() {
	scanf("%d", &N);
	P[0] = -1;
	REP(i,N-1) scanf("%d", P + i+1);
	REP(i,N) scanf("%d", C+i);

	REP(i,N-1) children[P[i+1]].push_back(i+1);

	dfs(0);

	printf("%d\n", (int)full[0]);

	return 0;
}