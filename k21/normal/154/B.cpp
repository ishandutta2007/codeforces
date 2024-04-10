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

#define MAX 100100

int N, M;

bool isPrime[MAX];
bool cUsed[MAX];
int pUsed[MAX];

set<int> fset[MAX];
vector<int> facts[MAX];

void sieve() {
	FOR(i,2,N) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= N; ++i) {
		set<int>::iterator it = fset[i].begin();
		while (it != fset[i].end()) {facts[i].push_back(*it); ++it;}
		if (!isPrime[i]) continue;
		facts[i].push_back(i);
		for (int j = 2*i; j <= N; j += i) {
			isPrime[j] = false;
			fset[j].insert(i);
		}
	}
}

int main() {
	scanf("%d%d\n", &N, &M);
	sieve();
	REP(i,N) pUsed[i] = false;
	REP(i,N) cUsed[i] = false;
	REP(r,M) {
		char cmd;
		int n;
		scanf("%c %d\n", &cmd, &n);
		if (cmd == '-') {
			if (!cUsed[n]) {puts("Already off"); continue;}
			cUsed[n] = false;
			REP(i,facts[n].size()) pUsed[facts[n][i]] = 0;
			puts("Success");
		} else {
			if (cUsed[n]) {puts("Already on"); continue;}
			int conflict = 0;
			REP(i,facts[n].size()) if (pUsed[facts[n][i]]) {conflict = pUsed[facts[n][i]]; break;}
			if (conflict) {printf("Conflict with %d\n", conflict); continue;}
			cUsed[n] = true;
			REP(i,facts[n].size()) pUsed[facts[n][i]] = n;
			puts("Success");
		}
	}
	return 0;
}