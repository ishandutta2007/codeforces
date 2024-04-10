#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& x : v)
        cin >> x;
    
    vector<vector<int>> groups(3);
    for (auto x : v) {
        bool p1 = true, p2 = true;
        int cur = 0;
        for (char c : x) {
            if (c == ')')
                cur--;
            else
                cur++;
            if (cur < 0)
                p1 = false;
        }

        reverse(x.begin(), x.end());
        int cur2 = 0;
        for (char c : x) {
            if (c == '(')
                cur2--;
            else
                cur2++;
            if (cur2 < 0)
                p2 = false;
        }

        reverse(x.begin(), x.end());
        // cout << x << " " << p1 << p2 << '\n';

        if (p1 && p2) {
            assert(cur == 0);
            groups[0].push_back(0);
        } else if (p1) {
            groups[1].push_back(cur);
        } else if (p2) {
            groups[2].push_back(cur2);
        }
    }

    int result = groups[0].size() / 2;
    sort(groups[1].begin(), groups[1].end());
    sort(groups[2].begin(), groups[2].end());
    auto it1 = groups[1].begin();
    auto it2 = groups[2].begin();
    while (it1 != groups[1].end() && it2 != groups[2].end()) {
        if (*it1 < *it2) {
            ++it1;
            continue;
        }
        if (*it1 > *it2) {
            ++it2;
            continue;
        }
        if (*it1 == *it2) {
            ++it1;
            ++it2;
            result++;
            continue;
        }
    }

    cout << result << '\n';
}