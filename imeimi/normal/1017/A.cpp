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

struct st {
    int a, b, c, d, i;
    void scan(int idx) {
        cin >> a >> b >> c >> d;
        i = idx;
    }
    int val() const {
        return a + b + c + d;
    }
    bool operator<(const st &p) const {
        if (val() != p.val()) return val() > p.val();
        return i < p.i;
    }
} ss[1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
        ss[i].scan(i);
	}
	
	sort(ss, ss + n);
	for (int i = 0; i < n; ++i) {
        if (ss[i].i == 0) {
            printf("%d\n", i + 1);
        }
	}
	
	return 0;
}