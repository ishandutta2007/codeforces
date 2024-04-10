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

int ansLen;
char ans[100010];

int main() {
	int i;
	int pos;
	
	for (; ~scanf("%s", S); ) {
		N = strlen(S);
		pos = 0;
		for (i = 0; i < N; ++i) {
			if (S[i] == '0') {
				pos = i;
				break;
			}
		}
		ansLen = 0;
		for (i = 0; i < N; ++i) if (i != pos) {
			ans[ansLen++] = S[i];
		}
		ans[ansLen] = 0;
		for (i = 0; i < ansLen && ans[i] == '0'; ++i);
		puts(ans);
	}
	
	return 0;
}