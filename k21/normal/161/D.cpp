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

struct node {
	vector<int> children;
	int parent;
	ll atd[550];
};

int N,K;
vector<int> edges[50100];
node nodes[50100];

void create(int i) {
	if (i == 0) {
		nodes[i].parent = -1;
	}
	REP(j,(int)edges[i].size()) {
		int t = edges[i][j];
		if (t == nodes[i].parent) continue;
		nodes[i].children.push_back(t);
		nodes[t].parent = i;
		create(t);
	}
}

void catd(int i) {
	REP(j,(int)nodes[i].children.size()) catd(nodes[i].children[j]);
	nodes[i].atd[0] = 1;
	FOR(d,1,540) {
		ll sum = 0;
		REP(j,(int)nodes[i].children.size()) sum += nodes[nodes[i].children[j]].atd[d-1];
		nodes[i].atd[d] = sum;
	}
}

ll cres(int i) {
	ll sum = 0;
	REP(j,(int)nodes[i].children.size()) sum += cres(nodes[i].children[j]);
	if (nodes[i].children.size() == 0) return sum;
	ll satd[540];
	REP(j,530) satd[j] = nodes[nodes[i].children[0]].atd[j];
	FOR(j,1,(int)nodes[i].children.size()-1) {
		FOR(d1,1,K-1) {
			int d2 = K-d1;
			sum += satd[d1-1]*nodes[nodes[i].children[j]].atd[d2-1];
		}
		REP(k,530) satd[k] += nodes[nodes[i].children[j]].atd[k];
	}
	sum += satd[K-1];
	return sum;
}

int main() {
	scanf("%d%d", &N, &K);
	REP(i,N-1) {
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		--n1; --n2;
		edges[n1].push_back(n2);
		edges[n2].push_back(n1);
	}
	create(0);
	catd(0);
	printf("%I64d\n", cres(0));
	return 0;
}