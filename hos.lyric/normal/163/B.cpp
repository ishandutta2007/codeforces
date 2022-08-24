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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, K;
double H;
pair<pint,int> P[100010];
int is[100010];

bool solve(double T) {
	int i, j;
	j = 1;
	for (i = 0; i < N; ++i) {
		if (P[i].first.second * T / 1e+9 >= j) {
			is[j] = P[i].second;
			if (j == K) {
				return 1;
			}
			++j;
		}
	}
	return 0;
}

int main() {
	int i, j;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		H = in();
		for (i = 0; i < N; ++i) {
			P[i].first.first = in();
		}
		for (i = 0; i < N; ++i) {
			P[i].first.second = in();
		}
		for (i = 0; i < N; ++i) {
			P[i].second = i;
		}
		sort(P, P + N);
		double lo = 0, ho = 1e+15;
		for (int reps = 100; reps--; ) {
			double mo = (lo + ho) / 2;
			solve(mo) ? (ho = mo) : (lo = mo);
		}
// cout<<"ho = "<<ho<<endl;
		solve(ho);
		for (j = 1; j <= K; ++j) {
			if (j > 1) printf(" ");
			printf("%d", is[j] + 1);
		}
		puts("");
	}
	
	return 0;
}