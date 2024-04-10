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

const int _ = 1000010;

char s[_];
int cC[_], cB[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n >> (s + 1);
		vector<int> pos;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == 'a') pos.push_back(i);
			cC[i] = cC[i - 1]; cB[i] = cB[i - 1];
			if (s[i] == 'b') cB[i]++;
			if (s[i] == 'c') cC[i]++;
		}
		int ans = n + 1;
		for (int i = 0; i != pos.size(); ++i)
			for (int j = i - 1; j >= max(0, i - 3); --j) {
				if (max(cB[pos[i]] - cB[pos[j]],
				        cC[pos[i]] - cC[pos[j]]) < i - j + 1)
					ans = min(ans, pos[i] - pos[j] + 1);
			}
		if (ans == n + 1) ans = -1;
		cout << ans << '\n';
	}

	return 0;
}