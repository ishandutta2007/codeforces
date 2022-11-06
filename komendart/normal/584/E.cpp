#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n), revp(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]); p[i]--;
        revp[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int t; scanf("%d", &t); t--;
        p[revp[t]] = i;
    }

    int sum = 0;
    vector< pair<int, int> > result;
    result.reserve(2e6);
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = i; j < n; j++) {
            if (p[j] == i) {
                pos = j;
                break;
            }
        }
        int cur = pos;
        sum += pos - i;
        for (int j = pos - 1; j >= i; j--) {
            if (cur <= p[j]) {
                result.push_back({j, cur});
                swap(p[cur], p[j]);
                cur = j;
            }
        }
    }

    printf("%d\n", sum);
    printf("%d\n", result.size());
    for (auto i: result) {
        printf("%d %d\n", i.first + 1, i.second + 1);
    }
}