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

int n;
struct rational {
    int b, a;
    bool operator<(const rational &p) const {
        return (llong)b * p.a > (llong)p.b * a;
    }
} pt[150000];

map<rational, vector<rational>> mp;

llong sum = 0;
const int inf = 1e9;
int check(ld c) {
    map<int, pair<ld, ld>> mx;
    llong asum = 0;
    for (auto &v : mp) {
        llong tsum = 0;
        ld d, u;
        for (rational i : v.second) {
            tsum += i.a;
        }
        for (rational i : v.second) {
            u = i.b * (1.0 - c * (asum + i.a) / sum);
            d = i.b * (1.0 - c * (asum + tsum) / sum);
            if (mx.find(i.b) != mx.end()) {
                mx[i.b].first = min(mx[i.b].first, d);
                mx[i.b].second = max(mx[i.b].second, u);
            }
            else mx[i.b] = { d, u };
        }
        asum += tsum;
    }
    auto it1 = mx.begin();
    auto it2 = ++mx.begin();
    while (it2 != mx.end()) {
        if (it1->second.second > it2->second.first) return 0;
        ++it1;
        ++it2;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pt[i].b;
	for (int i = 0; i < n; ++i) cin >> pt[i].a, sum += pt[i].a;
	for (int i = 0; i < n; ++i) mp[pt[i]].push_back(pt[i]);
	
	int s = 0, e = inf;
	while (s < e) {
        int m = (s + e + 1) / 2;
        if (check(m / (ld)inf)) s = m;
        else e = m - 1;
	}
	printf("%d.", s / inf);
	for (int i = inf / 10; i > 0; i /= 10) {
        printf("%d", s / i % 10);
	}
	printf("\n");
	return 0;
}