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

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

int tr[100100];

bool w[100100];
int as[100100];

bool did[100100];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	REP(i,N) {
		char c;
		int a;
		getchar();
		scanf("%c%d", &c, &a);
		--a;
		if (c == '-') {
			w[i] = false;
			as[i] = a;
		} else {
			w[i] = true;
			as[i] = a;
		}
	}
	int exp = 0;
	REP(i,N) {
		if (w[i]) {
			++tr[as[i]];
		} else {
			++exp;
			--tr[as[i]];
		}
	}
	int cnt = 0;
	REP(i,N) {
		if (exp+tr[i] == M) {did[i] = true; ++cnt;}
	}
	//REP(i,N) DEBUG(did[i])
	//REP(i,N) DEBUG(w[i])
	if (cnt == 1) {
		REP(i,N) {
			bool tr = (did[as[i]]) == (w[i]);
			puts(tr ? "Truth" : "Lie");
		}
	} else {
		REP(i,N) {
			if (w[i]) {
				if (did[as[i]]) puts("Not defined");
				else puts("Lie");
			} else {
				if (did[as[i]]) puts("Not defined");
				else puts("Truth");
			}
		}
	}
	return 0;
}