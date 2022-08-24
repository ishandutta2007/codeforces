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

int N;
char S[110];

int main() {
	
	
	for (; ~scanf("%s", S); ) {
		string ans = "";
		N = strlen(S);
		for (int h = 0; h < 1 << N; ++h) {
			string tmp = "";
			for (int i = 0; i < N; ++i) if (h & 1 << i) {
				tmp += S[i];
			}
			string rev = tmp;
			reverse(rev.begin(), rev.end());
			if (tmp == rev) {
				chmax(ans, tmp);
			}
		}
		puts(ans.c_str());
	}
	
	return 0;
}