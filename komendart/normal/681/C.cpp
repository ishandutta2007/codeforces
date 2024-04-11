#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    scanf("%d", &n);
    multiset<int> q;
    vector< pair<char, int> > ans;
    ans.reserve(1e6);
    for (int i = 0; i < n; i++) {
        char s[10];
        scanf("%s", s);
        if (s[0] == 'r') {
            if (q.empty()) {
                q.insert(1);
                ans.push_back({'i', 1});
            }
            q.erase(q.begin());
            ans.push_back({'r', -1});
        } else if (s[0] == 'i') {
            int x;
            scanf("%d", &x);
            q.insert(x);
            ans.push_back({'i', x});
        } else {
            int x;
            scanf("%d", &x);
            while (!q.empty() && *q.begin() < x) {
                ans.push_back({'r', -1});
                q.erase(q.begin());
            }
            if (q.empty() || *q.begin() > x) {
                ans.push_back({'i', x});
                q.insert(x);
            }
            ans.push_back({'g', x});
        }
    }

    printf("%d\n", (int) ans.size());
    for (auto p: ans) {
        if (p.first == 'r') {
            printf("removeMin\n");
        } else if (p.first == 'i') {
            printf("insert %d\n", p.second);
        } else {
            printf("getMin %d\n", p.second);
        }
    }
}