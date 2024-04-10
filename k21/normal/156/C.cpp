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

#define MOD 1000000007

int memo[3000][120];

int solve(int sum, int len) {
	if (sum < 0) return 0;
	int &res = memo[sum][len];
	if (res == -1) {
		if (len == 0) {
			if (sum != 0) res = 0;
			else res = 1;
		}
		else {
			res = 0;
			REP(n,26) {
				res += solve(sum-n, len-1);
				res %= MOD;
			}
		}
	}
	return res;
}

char data[120];

int main() {
	int T;
	scanf("%d", &T);
	REP(i,3000)REP(j,120) memo[i][j] = -1;
	REP(t,T) {
		getchar();
		scanf("%s", data);
		int l = strlen(data);
		int sum = 0;
		REP(i,l) sum += data[i]-'a';
		int res = solve(sum,l);
		printf("%d\n", res-1);
	}
	return 0;
}