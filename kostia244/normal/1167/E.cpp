#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma,sse,sse2,ssse3,tune=native")
#pragma GCC optimize("unroll-loops")
#include <memory.h>
#include <cassert>
#include <stddef.h>
/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) noexcept { }
/** End fast allocation */

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) noexcept { assert(0); }
#include "bits/stdc++.h"
#define left tuna
#define right uno
using ll = long long;
using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

int n, x, r = 0, LIS = 0, a[N];
ll ans = 0;
bitset<N> left, right;
set<int> s;
vector<int> id[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(i);
		id[a[i]].push_back(i);
	}
	a[n + 1] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] <= a[i]) {
			left[i] = 1;
		}
		if (a[i] <= a[i + 1]) {
			right[i] = 1;
		}
		if (left[i] && right[i]) {
			LIS++;
		}
	}
	left[0] = 1;
	right[n + 1] = 1;
	for (int l = 1; l <= x; l++) {
		for (auto cid : id[l - 1]) {
			auto it = s.lower_bound(cid);
			int L = 0, R = n + 1;
			if (it != s.end()) {
				R = *it;
			}
			if (it != s.begin()) {
				L = *--it;
			}
			if (!(L == 0 && R == n + 1) && a[L] <= a[R]) {
				if (L != 0 && left[L] && right[L]) {
					LIS--;
				}
				if (R != n + 1 && left[R] && right[R]) {
					LIS--;
				}
				right[L] = left[R] = 0;
			}
			if (L != 0 && a[L] <= l) {
				if (!right[L]) {
					if (left[L]) {
						LIS++;
					}
					right[L] = 1;
				}
			}
			if (R != n + 1 && l <= a[R]) {
				if (!left[R]) {
					if (right[R]) {
						LIS++;
					}
					left[R] = 1;
				}
			}
			if (a[L] <= l) {
				left[cid] = 1;
			}
			if (l <= a[R]) {
				right[cid] = 1;
			}
			if (a[L] <= l && l <= a[R]) {
				LIS++;
			}
			s.insert(cid);
		}
		while (r < l || LIS != int(s.size())) {
			r++;
			if (r > x) {
				break;
			}
			for (auto cid : id[r]) {
				if (left[cid] && right[cid]) {
					LIS--;
				}
				left[cid] = right[cid] = 0;
				auto it = s.find(cid);
				int L = 0, R = n + 1;
				if (it != s.begin()) {
					L = *--it;
					it++;
				}
				if (++it != s.end()) {
					R = *it;
				}
				if (!(L == 0 && R == n + 1) && a[L] <= a[R]) {
					if (L != 0 && !right[L]) {
						if (left[L]) {
							LIS++;
						}
						right[L] = 1;
					}
					if (R != n + 1 && !left[R]) {
						if (right[R]) {
							LIS++;
						}
						left[R] = 1;
					}
				}
				s.erase(cid);
			}
		}
		if (LIS == int(s.size())) {
			ans += x - r + 1;
		}
	}
	cout << ans;
}