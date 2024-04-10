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

const int MAX = 100100;

int N, M;

vector<int> edges[MAX];
bool visited[MAX];
bool resolved[MAX];
vector<int> out[3];

int dfs(int i, int parent) {
	if (visited[i]) {
		return -1;
	}
	visited[i] = true;
	int last = -1;
	REP(jj, (int)edges[i].size()) {
		int j = edges[i][jj];
		if (j == parent) continue;
		if (resolved[j]) continue;
		int extra = dfs(j, i);
		//printf("%d -> %d = %d\n", i+1, j+1, extra+1);
		if (extra == -1) {
			if (last == -1) {
				last = j;
			} else {
				out[0].push_back(last);
				out[1].push_back(i);
				out[2].push_back(j);
				last = -1;
			}
		} else {
			out[0].push_back(extra);
			out[1].push_back(j);
			out[2].push_back(i);
		}
	}
	resolved[i] = true;

	return last;
}

int main() {
	scanf("%d%d", &N, &M);
	REP(i, M) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int r = dfs(0, -1);
	if (r == -1 && 2*(int)out[0].size() == M) {
		REP(i, (int)out[0].size()) {
			printf("%d %d %d\n", out[0][i] + 1, out[1][i] + 1, out[2][i] + 1);
		}
	} else {
		printf("No solution\n");
	}

	return 0;
}