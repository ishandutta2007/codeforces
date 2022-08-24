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

int X;

bool solve(int n) {
	if (n % 2 == 0) {
		int mx = (n - 2) * (n - 2) / 2;
		return (X <= mx && (mx - X) % 4 == 0);
	} else {
		for (int phase = 0; phase < 2; ++phase) {
			int ones, twos, fours;
			if (phase == 0) {
				ones = 1;
				twos = n / 2 / 2 * 2;
				fours = ((n / 2) * (n / 2) + 1) / 2;
			} else {
				ones = 0;
				twos = (n / 2 + 1) / 2 * 2;
				fours = ((n / 2) * (n / 2)) / 2;
			}
// cout<<n<<"  "<<ones<<" "<<twos<<" "<<fours<<endl;
assert(ones*1+twos*2+fours*4==(n*n+1-phase)/2);
			for (int a = 0; a <= ones; ++a) for (int b = 0; b <= twos; ++b) for (int c = 0; c <= fours; ++c) {
				if (a * 1 + b * 2 + c * 4 == X) {
					return true;
				}
			}
		}
		return false;
	}
}

int main() {
	
	
	for (; ~scanf("%d", &X); ) {
		for (int n = 1; ; ++n) {
			if (solve(n)) {
				printf("%d\n", n);
				break;
			}
		}
	}
	
	return 0;
}