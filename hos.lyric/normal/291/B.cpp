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

int N;
char S[100010];

int asLen;
int as[100010];

void solve(int a, int b) {
	istringstream iss(string(S + a, S + b));
	for (string str; iss >> str; ) {
		printf("<%s>\n", str.c_str());
	}
}

int main() {
	int i, j;
	
	for (; gets(S); ) {
		N = strlen(S);
		asLen = 0;
		for (i = 0; i < N; ++i) {
			if (S[i] == '\"') {
				as[asLen++] = i;
			}
		}
		as[asLen] = N;
		solve(0, as[0]);
		for (j = 0; j < asLen; j += 2) {
			printf("<%s>\n", string(S + as[j] + 1, S + as[j + 1]).c_str());
			solve(as[j + 1] + 1, as[j + 2]);
		}
cerr<<"===="<<endl;
	}
	
	return 0;
}