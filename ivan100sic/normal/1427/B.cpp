// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> gaps;
        int run = 0, score = 0, winr = 0;
        for (char c : s) {
            if (c == 'L') {
                run++;
            } else if (run > 0) {
                gaps.push_back(run);
                run = 0;
            }

            if (c == 'W') {
                winr++;
                score += min(2, winr);
            } else {
                winr = 0;
            }
        }
        if (run > 0) {
            gaps.push_back(run);
        }
        
        int cl = count(begin(s), end(s), 'L');
        if (cl == n) {
            // me playing chess
            cout << max(0, 2*k-1) << '\n';
        } else if (cl <= k) {
            cout << 2*n-1 << '\n';
        } else {
            if (s[0] == 'L') {
                gaps.erase(gaps.begin());
            }

            if (s.back() == 'L') {
                gaps.erase(--gaps.end());
            }

            sort(begin(gaps), end(gaps));
            for (int x : gaps) {
                if (x <= k) {
                    k -= x;
                    score += 2*x + 1;
                } else {
                    break;
                }
            }

            score += 2*k;
            cout << score << '\n';
        }
    }
}