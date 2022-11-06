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

vector<int> divv[100001];
llong solve(int a, int b, int c) {
    llong ret = 0;
    vector<int> vt;
    for (int i : divv[a]) vt.push_back(i);
    for (int i : divv[b]) vt.push_back(i);
    for (int i : divv[c]) vt.push_back(i);
    sort(vt.begin(), vt.end());
    vt.erase(unique(vt.begin(), vt.end()), vt.end());
    llong x[8] = {};
    for (int i : vt) {
        int p = ((a % i == 0) << 2) | ((b % i == 0) << 1) | (c % i == 0);
        ++x[p];
    }
    ret += x[7] * x[7];
    ret += x[7] * (x[7] - 1) * (x[7] - 2) / 6;
    ret += x[4] * x[2] * (x[1] + x[5] + x[3]);
    ret += x[4] * x[1] * (x[6] + x[3]);
    ret += x[2] * x[1] * (x[6] + x[5]);
    ret += (x[1] * x[2] + x[2] * x[4] + x[4] * x[1]) * x[7];
    ret += x[4] * x[3] * (x[3] + 1) / 2;
    ret += x[2] * x[5] * (x[5] + 1) / 2;
    ret += x[1] * x[6] * (x[6] + 1) / 2;
    ret += (x[4] + x[2] + x[1]) * (x[6] * x[5] + x[5] * x[3] + x[3] * x[6]);
    
    ret += x[7] * (x[4] + x[2] + x[1]) * (x[6] + x[5] + x[3]);
    
    ret += x[7] * (x[7] + 1) / 2 * (x[4] + x[2] + x[1]);
    
    ret += x[6] * (x[6] + 1) / 2 * (x[5] + x[3]);
    ret += x[5] * (x[5] + 1) / 2 * (x[3] + x[6]);
    ret += x[3] * (x[3] + 1) / 2 * (x[6] + x[5]);
    ret += x[3] * x[5] * x[6];
    
    ret += x[7] * (x[6] * (x[6] + 1) / 2);
    ret += x[7] * (x[5] * (x[5] + 1) / 2);
    ret += x[7] * (x[3] * (x[3] + 1) / 2);
    ret += x[7] * (x[6] * x[5] + x[5] * x[3] + x[3] * x[6]);
    ret += x[7] * (x[7] + 1) / 2 * (x[6] + x[5] + x[3]);
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i <= 100000; ++i) {
        for (int j = i; j <= 100000; j += i) {
            divv[j].push_back(i);
        }
	}
	int t;
	cin >> t;
	while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        printf("%lld\n", solve(a, b, c));
	}
	return 0;
}