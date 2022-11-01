#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
using namespace std;


typedef pair<int, int> pii;
typedef long long ll;

vector<pii> points;

ll result;

inline ll sqr(int p) {
    return p * ll(p);
}

inline void update(const pii & a, const pii & b) {
    ll dist = sqr(a.first - b.first) + sqr(a.second - b.second);
	result = min(result, dist);
}

bool compare_by_second(const pii& left, const pii& right) {
    return left.second < right.second;
}

const int MAXN = int(1e5);

void solve(int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i <= r; ++i)
			for (int j = i+1; j <= r; ++j)
				update(points[i], points[j]);
        sort(points.begin() + l, points.begin() + r + 1, compare_by_second);
		return;
	}
 
	int m = (l + r) / 2;
	int midx = points[m].first;
    solve(l, m);
    solve(m + 1, r);
	static pii t[MAXN];
    merge (points.begin() + l, points.begin() + m + 1, points.begin() + m + 1, points.begin() + r + 1, t, compare_by_second);
	copy(t, t + r - l + 1, points.begin() + l);
 
	int i2 = 0;
	for (int i = l; i <= r; ++i)
		if (sqr(points[i].first - midx) < result) {
            for (int j = i2 - 1;
                j>=0 && sqr(points[i].second - t[j].second) < result;
                --j) {
                    update (points[i], t[j]);
            }
			t[i2++] = points[i];
		}
}

int main(void) {
    int n;
    scanf("%d", &n);
    //points.resize(n);
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        x += a;
        points.push_back(pii(i, x));
    }
    sort (points.begin(), points.end());
    result = LLONG_MAX;
    solve(0, n-1);
    cout << result << endl;
}