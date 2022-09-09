#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int _ = 100010;

int ans[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N, A, B; cin >> N >> A >> B;
		if (A == 0 && B == 0) {
			for (int i = 1; i <= N; ++i) cout << i << " \n"[i == N];
			continue;
		}
		int l = 0, r = 0;
		bool fl = true;
		if (A + B > N - 2) fl = false;
		else {
			ans[1] = l;
			if (A >= B) {
				if (A - B > 1) fl = false;
				ans[2] = ++r;
				for (int i = 1; i <= A + B; ++i) {
					if (i & 1) ans[i + 2] = --l;
					else ans[i + 2] = ++r;
				}
				for (int i = A + B + 3; i <= N; ++i) if (ans[i - 1] > ans[i - 2]) ans[i] = ++r;
				else ans[i] = --l;
			} else {
				if (B - A > 1) fl = false;
				ans[2] = --l;
				for (int i = 1; i <= A + B; ++i) {
					if (i & 1) ans[i + 2] = ++r;
					else ans[i + 2] = --l;
				}
				for (int i = A + B + 3; i <= N; ++i) if (ans[i - 1] > ans[i - 2]) ans[i] = ++r;
				else ans[i] = --l;
			}
			
		}
		if (!fl) cout << "-1\n";
			else for (int i = 1; i <= N; ++i) cout << (ans[i] - l + 1) << " \n"[i == N];
	}

	return 0;
}