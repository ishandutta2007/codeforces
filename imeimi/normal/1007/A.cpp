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
int a[100001];

int check(int x) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < x; ++i) {
        pq.push(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!pq.empty() && pq.top() < a[i]) pq.pop();
    }
    return pq.empty();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
        cin >> a[i];
	}
	sort(a, a + n);
	int s = 0, e = n;
	while (s < e) {
        int m = (s + e + 1) / 2;
        if (check(m)) s = m;
        else e = m - 1;
	}
	printf("%d\n", s);
	return 0;
}