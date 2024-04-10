#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const int INF = 1001001001;

char buf[110];

int N;

int asLen, as[500010];
int nxt[20][500010];
int dp[33010][110];

int solve(const map<string,int> &tr) {
	asLen = 0;
	for (int numWords = in(); numWords--; ) {
		scanf("%s", buf);
		if (tr.count(buf)) {
			as[asLen++] = tr.at(buf);
		}
	}
// cout<<"as : ";pv(as,as+asLen);
	for (int i = 0; i < N; ++i) {
		nxt[i][asLen] = asLen + 1;
		for (int j = asLen; j--; ) {
			nxt[i][j] = (as[j] == i) ? (j + 1) : nxt[i][j + 1];
		}
	}
	for (int h = 0; h < 1 << N; ++h) {
		memset(dp[h], 0x3f, (N * (N - 1) / 2 + 1) * 4);
	}
	dp[0][0] = 0;
	for (int h = 0; h < 1 << N; ++h) for (int x = 0; x <= N * (N - 1) / 2; ++x) if (dp[h][x] <= asLen) {
// cout<<h<<" "<<x<<" : "<<dp[h][x]<<endl;
		for (int i = 0; i < N; ++i) if (!(h & 1 << i)) {
			chmin(dp[h | 1 << i][x + __builtin_popcount(h >> i)], nxt[i][dp[h][x]]);
		}
	}
	for (int x = 0; x <= N * (N - 1) / 2; ++x) {
		if (dp[(1 << N) - 1][x] <= asLen) {
// cout<<"found "<<x<<endl;
			return x;
		}
	}
	return INF;
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		map<string,int> tr;
		for (int i = 0; i < N; ++i) {
			scanf("%s", buf);
			tr[buf] = i;
		}
		const int m = in();
		int ans = INF;
		int jm = -1;
		for (int j = 0; j < m; ++j) {
			const int res = solve(tr);
			if (ans > res) {
				ans = res;
				jm = j;
			}
		}
		if (!~jm) {
			puts("Brand new problem!");
		} else {
			printf("%d\n", jm + 1);
			printf("[:%s:]\n", string(N * (N - 1) / 2 - ans + 1, '|').c_str());
		}
	}
	
	return 0;
}