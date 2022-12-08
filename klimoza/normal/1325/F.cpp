#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
 
#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
 
const int MAXN = 100000;
 
int n, m;
vector<int> adj[MAXN];
int anskind;
vector<int> cyc;
vector<int> indep;
 
bool intree[MAXN];
int par[MAXN];
int dep[MAXN];
 
int chcnt[MAXN];
int q[MAXN], qhead, qtail;
bool alive[MAXN];
 
void dfsinit(int at) {
	intree[at] = true; dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (intree[to]) continue;
		par[to] = at; dfsinit(to);
	}
}
 
 
void solve() {
	REP(i, n) intree[i] = false; par[0] = -1; dfsinit(0);
 
	REP(i, n) alive[i] = true, chcnt[i] = 0;
	REP(i, n) if (par[i] != -1) ++chcnt[par[i]];
	qhead = qtail = 0; REP(i, n) if (chcnt[i] == 0) q[qhead++] = i;
	indep.clear();
 
	int	need = 0; while (need * need < n) ++need;
	while (qtail < qhead) {
		int at = q[qtail++];
		int upto = dep[at];
		REPSZ(i, adj[at]) {
			int to = adj[at][i];
			upto = min(upto, dep[to]);
			if (dep[at] - dep[to] >= need - 1) {
				anskind = 2; cyc.clear();
				for (int x = at;; x = par[x]) { cyc.PB(x); if (x == to) break; }
				return;
			}
		}
		if (alive[at]) {
			indep.PB(at);
			for (int x = at; x != -1 && dep[x] >= upto; x = par[x]) alive[x] = false;
		}
		if (par[at] != -1) {
			if (--chcnt[par[at]] == 0) q[qhead++] = par[at];
		}
	}
	assert(SZ(indep) >= need);
	indep.resize(need);
	anskind = 1;
}
 
void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	solve();
	printf("%d\n", anskind);
	if (anskind == 1) {
		REPSZ(i, indep) { if (i != 0) printf(" "); printf("%d", indep[i] + 1); } puts("");
	}
	if (anskind == 2) {
		printf("%d\n", SZ(cyc));
		REPSZ(i, cyc) { if (i != 0) printf(" "); printf("%d", cyc[i] + 1); } puts("");
	}
}
 
int main() {
	run();
	return 0;
}