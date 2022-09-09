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

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int n; string s; cin >> n >> s;
		if (is_sorted(s.begin(), s.end())) {
			cout << "0\n";
			continue;
		}
		int l = 0, r = n - 1;
		vector<int> x, y;
		while (true) {
			while (l < r) {
				if (s[l] == '0') ++l;
				if (s[r] == '1') --r;
				if (l < r && s[l] == '1' && s[r] == '0') break;
			}
			if (l < r && s[l] == '1' && s[r] == '0') {
				x.push_back(l); y.push_back(r);
			} else break;
			++l; --r;
		}
		cout << "1\n";
		cout << x.size() * 2;
		for (int i = 0; i != x.size(); ++i) cout << ' ' << x[i] + 1;
		for (int i = 0; i != x.size(); ++i) cout << ' ' << y[x.size() - i - 1] + 1;
		cout << '\n';
	}

	return 0;
}