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

const int inf = 1e9;
int n, k, b, c;
int t[200000];
int a[200000];

llong solve(vector<int> &qs, int r) {
    for (int i = 0; i < n; ++i) a[i] = t[i] - r;
    priority_queue<llong> pq;
    llong sum = 0, ans = 1e18;
    int j = 0;
    for (int i : qs) {
        i -= r;
        while (j < n && a[j] <= i) {
            llong d = (inf + inf + 5ll - a[j]) % 5;
            llong v = d * c - (a[j] + d) * b / 5;
            pq.push(v);
            sum += v;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ++j;
        }
        if (pq.size() == k) {
            ans = min(ans, sum + (llong)k * i * b / 5);
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d%d", &n, &k, &b, &c);
    b = min(b, 5 * c);
    vector<int> qs[5];
    for (int i = 0; i < n; ++i) {
        scanf("%d", t + i);
        t[i] += inf;
        for (int j = 0; j < 5; ++j) {
            qs[(t[i] + j) % 5].push_back(t[i] + j);
        }
    }
    sort(t, t + n);
    for (int i = 0; i < 5; ++i) {
        sort(qs[i].begin(), qs[i].end());
        qs[i].erase(unique(qs[i].begin(), qs[i].end()), qs[i].end());
    }
    llong ans = 1e18;
    for (int i = 0; i < 5; ++i) {
        ans = min(ans, solve(qs[i], i));
    }
    printf("%lld\n", ans);
	return 0;
}