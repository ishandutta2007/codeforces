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

int score[100];

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	REP(i,N) {
		scanf("%d", score+i);
	}
	vector<pair<int,int> > sc;
	REP(i,N) sc.push_back(make_pair(score[i],i));
	sort(sc.begin(), sc.end());
	int lim = sc[N-K].first;
	if (lim < 1) lim = 1;
	int res = 0;
	REP(i,N) if (score[i] >= lim) ++res;
	printf("%d\n", res);
	return 0;
}