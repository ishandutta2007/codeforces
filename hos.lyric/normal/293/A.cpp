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

#define MAX 2000010

int N;
char A[MAX], B[MAX];

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		scanf("%s%s", A, B);
		int x = 0;
		int ys[2] = {};
		for (i = 0; i < N * 2; ++i) {
			if (A[i] == '1' && B[i] == '1') ++x;
			if (A[i] == '1' && B[i] != '1') ++ys[0];
			if (A[i] != '1' && B[i] == '1') ++ys[1];
		}
// cout<<x<<" "<<ys[0]<<" "<<ys[1]<<endl;
		int pts[2] = {};
		for (i = 0; i < N * 2; ++i) {
			int me = i % 2;
			if (x) {
				--x;
				++pts[me];
			} else if (ys[me]) {
				--ys[me];
				++pts[me];
			} else if (ys[me ^ 1]) {
				--ys[me ^ 1];
			}
		}
// cout<<pts[0]<<" "<<pts[1]<<endl;
		puts((pts[0] > pts[1]) ? "First" : (pts[0] < pts[1]) ? "Second" : "Draw");
	}
	
	return 0;
}