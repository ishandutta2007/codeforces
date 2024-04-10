#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m;
int a[200001];
int f[200001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	vector<int> str;
	vector<int> pat;
	for (int i = 0; i < n + n - 1; ++i) {
        str.push_back((a[(i + 1) % n] - a[i % n] + m) % m);
        if (i < n) pat.push_back((a[(i + 1) % n] - a[i % n] + m) % m);
	}
	reverse(pat.begin(), pat.end());
	for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && pat[i] != pat[j]) j = f[j - 1];
        if (pat[i] == pat[j]) f[i] = ++j;
	}
	
	vector<int> ans;
	for (int i = 0, j = 0; i < n + n - 1; ++i) {
        while (j > 0 && str[i] != pat[j]) j = f[j - 1];
        if (str[i] == pat[j]) {
            if (j + 1 == n) {
                ans.push_back((a[i - n + 1] + a[0]) % m);
                j = f[n - 1];
            }
            else {
                ++j;
            }
        }
	}
	
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i : ans) printf("%d ", i);
	printf("\n");
	return 0;
}