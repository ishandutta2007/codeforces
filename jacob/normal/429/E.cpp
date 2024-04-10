#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int n;

typedef pair<int, int> pii;

vector<pii> intervals;
vector<char> answer;

set<pii> interval_by_start;

int add(int l, int r) {
    int result = static_cast<int>(intervals.size());
    intervals.push_back(pii(l, r));
    interval_by_start.insert(pii(l, result));
    answer.push_back(2);
    return result;
}

void solve() {
    auto iter = interval_by_start.begin();
    auto iter2 = iter;
    ++iter2;
    if (iter2 == interval_by_start.end()) {
        answer[iter->second] = 0;
        return;
    }
    if (intervals[iter->second].second < iter2->first) {
        answer[iter->second] = 0;
        interval_by_start.erase(iter);
        solve();
    } else {
        int i1 = iter->second, i2 = iter2->second;
        interval_by_start.erase(interval_by_start.begin());
        interval_by_start.erase(interval_by_start.begin());
        int i3 = add(min(intervals[i1].second, intervals[i2].second), max(intervals[i1].second, intervals[i2].second));
        solve();
        if (intervals[i1].second < intervals[i2].second) {
            answer[i1] = 1 - answer[i3];
            answer[i2] = answer[i3];
        } else {
            answer[i1] = answer[i3];
            answer[i2] = 1 - answer[i3];
        }
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        add(l, r);
    }
    solve();
    for (int i = 0; i < n; ++i)
        printf("%d ", int(answer[i]));
    printf("\n");
    return 0;
}